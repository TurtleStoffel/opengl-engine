#include "engine/objects/sun.hpp"

#include "engine/color.hpp"
#include "engine/components/collider.hpp"
#include "engine/components/effect.hpp"
#include "engine/components/effects/glow.hpp"
#include "engine/components/gui/composite_gui.hpp"
#include "engine/components/models/model_factory.hpp"
#include "engine/components/models/sphere.hpp"
#include "engine/components/shader_component.hpp"
#include "engine/components/shaders/generic_shader_component.hpp"
#include "engine/shaders/shaderregistry.hpp"
#include "engine/shaders/sun_shader.hpp"

#include <memory>
#include <utility>

namespace Engine {
    auto Sun::createDefault(const ShaderRegistry& shaderRegistry) -> std::unique_ptr<Sun> {
        auto sun = std::make_unique<Sun>();

        sun->registerComponent<Components::ShaderComponent>(
            std::make_unique<Components::Shaders::GenericShaderComponent>(*sun,
                                                                          shaderRegistry
                                                                              .get<SunShader>()));

        sun->registerComponent<Components::GuiComponent>(
            std::make_unique<Components::Gui::CompositeGui>(*sun));

        sun->createAndRegisterComponent<Components::Transform>(*sun);
        sun->createAndRegisterComponent<Components::Collider>(*sun);

        return sun;
    }

    Sun::Sun()
          : Entity{nullptr, "Sun"} {
        auto effectComponent = std::make_unique<Components::Effect>(*this);
        effectComponent->addPreRenderEffect(std::make_unique<Components::Effects::Glow>(*this));
        registerComponent<Components::Effect>(std::move(effectComponent));

        auto colorGenerator = [this]([[maybe_unused]] float height) {
            return color::starColor(m_temperature);
        };
        auto model = Components::Models::ModelFactory::make<
            Components::Models::Sphere>(*this, colorGenerator);

        registerComponent<Components::Model>(std::move(model));
    }
}