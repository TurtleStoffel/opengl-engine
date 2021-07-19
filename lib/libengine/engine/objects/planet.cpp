#include "engine/objects/planet.hpp"

#include "engine/components/collider.hpp"
#include "engine/components/color_selector.hpp"
#include "engine/components/gui/composite_gui.hpp"
#include "engine/components/gui/planet_gui.hpp"
#include "engine/components/gui_component.hpp"
#include "engine/components/models/model_factory.hpp"
#include "engine/components/models/sphere.hpp"
#include "engine/components/shader_component.hpp"
#include "engine/components/shaders/generic_shader_component.hpp"
#include "engine/models/effects/outline.hpp"
#include "engine/shaders/lowpolyshader.hpp"
#include "engine/shaders/shaderregistry.hpp"
#include "engine/util.hpp"

#include <math.h>
#include <utility>

namespace Engine {
    auto Planet::createDefault(float distance, float radius, const ShaderRegistry& shaderRegistry)
        -> std::unique_ptr<Planet> {
        auto planet = std::make_unique<Planet>(distance);

        planet->registerComponent<Components::ShaderComponent>(
            std::make_unique<
                Components::Shaders::GenericShaderComponent>(*planet,
                                                             shaderRegistry.get<LowPolyShader>()));

        auto transform = std::make_unique<Components::Transform>(*planet);
        transform->scale(glm::vec3{radius, radius, radius});
        planet->registerComponent<Components::Transform>(std::move(transform));

        planet->registerComponent<Components::Collider>(
            std::make_unique<Components::Collider>(*planet));

        auto compositeGui = std::make_unique<Components::Gui::CompositeGui>(*planet);
        compositeGui->addSubcomponent(std::make_unique<Components::Gui::PlanetGui>(*planet));
        planet->registerComponent<Components::GuiComponent>(std::move(compositeGui));

        planet->registerComponent<Components::ColorSelector>(
            std::make_unique<Components::ColorSelector>(*planet));

        return planet;
    }

    Planet::Planet(float distance)
          : Entity{nullptr, "Planet"}
          , m_rotationalSpeed{util::randf(0.00003f, 0.0001f)}
          , m_rotationAngle{util::randRadian()}
          , m_distance{distance} {
        auto lambda = [this](float height) {
            auto colorSelector = get<Components::ColorSelector>();
            if (colorSelector) {
                return colorSelector->getColor(height);
            } else {
                constexpr auto CUTOFF_1 = 0.95f;
                constexpr auto CUTOFF_2 = 0.60f;
                constexpr auto CUTOFF_3 = 0.50f;

                if (height > CUTOFF_1) {
                    return color::grey;
                } else if (height > CUTOFF_2) {
                    auto fraction = (height - CUTOFF_2) / (CUTOFF_1 - CUTOFF_2);
                    return color::interpolate(color::brown, color::darkGrey, fraction);
                } else if (height > CUTOFF_3) {
                    auto fraction = (height - CUTOFF_3) / (CUTOFF_2 - CUTOFF_3);
                    return color::interpolate(color::darkGreen, color::brown, fraction);
                } else {
                    return color::darkGreen;
                }
            }
        };
        auto model = Components::Models::ModelFactory::make<Components::Models::Sphere>(*this,
                                                                                        lambda);
        model->addPreRenderEffect(std::make_unique<Outline>(*model));
        registerComponent<Components::Model>(std::move(model));
    }
}