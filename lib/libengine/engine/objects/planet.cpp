#include "engine/objects/planet.hpp"

#include "engine/color.hpp"
#include "engine/components/collider.hpp"
#include "engine/components/color_selector.hpp"
#include "engine/components/effect.hpp"
#include "engine/components/effects/outline.hpp"
#include "engine/components/gui/composite_gui.hpp"
#include "engine/components/gui/planet_gui.hpp"
#include "engine/components/gui_component.hpp"
#include "engine/components/models/model_factory.hpp"
#include "engine/components/models/sphere.hpp"
#include "engine/components/shader_component.hpp"
#include "engine/components/shaders/generic_shader_component.hpp"
#include "engine/components/state/planet_state.hpp"
#include "engine/noise/simplex_noise.hpp"
#include "engine/objects/entity.hpp"
#include "engine/shaders/lowpolyshader.hpp"
#include "engine/shaders/shaderregistry.hpp"
#include "engine/util.hpp"

#include <math.h>
#include <utility>

namespace Engine {
    auto Planet::createDefault(float distance, float radius, const ShaderRegistry& shaderRegistry)
        -> std::unique_ptr<Entity> {
        auto entity = std::make_unique<Entity>(nullptr, "Planet");

        auto planetState               = std::make_unique<Components::PlanetState>(*entity);
        planetState->m_rotationalSpeed = util::randf(0.00003f, 0.0001f);
        planetState->m_rotationAngle   = util::randRadian();
        planetState->m_distance        = distance;
        entity->registerComponent<Components::PlanetState>(std::move(planetState));

        auto colorFunction = [entity = entity.get()](float height) {
            auto colorSelector = entity->get<Components::ColorSelector>();
            if (colorSelector) {
                return colorSelector->getColor(height);
            } else {
                constexpr auto CUTOFF_1 = 0.95f;
                constexpr auto CUTOFF_2 = 0.60f;
                constexpr auto CUTOFF_3 = 0.50f;

                if (height > CUTOFF_1) {
                    return Color::grey;
                } else if (height > CUTOFF_2) {
                    auto fraction = (height - CUTOFF_2) / (CUTOFF_1 - CUTOFF_2);
                    return Color::interpolate(Color::brown, Color::darkGrey, fraction);
                } else if (height > CUTOFF_3) {
                    auto fraction = (height - CUTOFF_3) / (CUTOFF_2 - CUTOFF_3);
                    return Color::interpolate(Color::darkGreen, Color::brown, fraction);
                } else {
                    return Color::darkGreen;
                }
            }
        };
        auto noiseFunction = [](glm::vec3& point) {
            float noise = SimplexNoise::noise(point.x * 2.0f, point.y * 2.0f, point.z * 2.0f);
            // Noise in range [0, 1]
            auto normalizedHeight = (noise + 1.0f) / 2.0f;

            auto heightFactor = 1.0f + noise / 15.0f;
            point *= heightFactor;
            return normalizedHeight;
        };
        auto effectComponent = std::make_unique<Components::Effect>(*entity);
        effectComponent->addPreRenderEffect(
            std::make_unique<Components::Effects::Outline>(*entity));
        entity->registerComponent<Components::Effect>(std::move(effectComponent));

        auto model = Components::Models::ModelFactory::make<
            Components::Models::Sphere>(*entity, colorFunction, noiseFunction);
        entity->registerComponent<Components::Model>(std::move(model));

        entity->registerComponent<Components::ShaderComponent>(
            std::make_unique<
                Components::Shaders::GenericShaderComponent>(*entity,
                                                             shaderRegistry.get<LowPolyShader>()));

        auto transform = std::make_unique<Components::Transform>(*entity);
        transform->scale(glm::vec3{radius, radius, radius});
        entity->registerComponent<Components::Transform>(std::move(transform));

        entity->createAndRegisterComponent<Components::Collider>(*entity);

        auto compositeGui = std::make_unique<Components::Gui::CompositeGui>(*entity);
        compositeGui->addSubcomponent(std::make_unique<Components::Gui::PlanetGui>(*entity));
        entity->registerComponent<Components::GuiComponent>(std::move(compositeGui));

        entity->createAndRegisterComponent<Components::ColorSelector>(*entity);

        return entity;
    }
}