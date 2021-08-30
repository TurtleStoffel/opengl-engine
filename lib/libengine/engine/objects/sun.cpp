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
#include "engine/components/state/sun_state.hpp"
#include "engine/shaders/shaderregistry.hpp"
#include "engine/shaders/sun_shader.hpp"

#include <memory>
#include <utility>

namespace Engine {
    auto Sun::createDefault(const ShaderRegistry& shaderRegistry) -> std::unique_ptr<Entity> {
        auto entity = std::make_unique<Entity>(nullptr, "Sun");

        entity->createAndRegisterComponent<Components::SunState>(*entity);

        auto effectComponent = std::make_unique<Components::Effect>(*entity);
        effectComponent->addPreRenderEffect(std::make_unique<Components::Effects::Glow>(*entity));
        entity->registerComponent<Components::Effect>(std::move(effectComponent));

        auto colorGenerator = [entity = entity.get()]([[maybe_unused]] float height) {
            auto& sunState = entity->getRequired<Components::SunState>();
            return Color::starColor(sunState.m_temperature);
        };

        auto model = Components::Models::ModelFactory::make<
            Components::Models::Sphere>(*entity, colorGenerator);
        entity->registerComponent<Components::Model>(std::move(model));

        entity->registerComponent<Components::ShaderComponent>(
            std::make_unique<Components::Shaders::GenericShaderComponent>(*entity,
                                                                          shaderRegistry
                                                                              .get<SunShader>()));

        entity->registerComponent<Components::GuiComponent>(
            std::make_unique<Components::Gui::CompositeGui>(*entity));

        entity->createAndRegisterComponent<Components::Transform>(*entity);
        entity->createAndRegisterComponent<Components::Collider>(*entity);

        return entity;
    }
}