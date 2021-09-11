#include "engine/objects/star.hpp"

#include "engine/components/collider.hpp"
#include "engine/components/effect.hpp"
#include "engine/components/effects/glow.hpp"
#include "engine/components/gui/composite_gui.hpp"
#include "engine/components/models/model_factory.hpp"
#include "engine/components/models/sphere.hpp"
#include "engine/components/shader_component.hpp"
#include "engine/components/shaders/generic_shader_component.hpp"
#include "engine/components/state/star_state.hpp"
#include "engine/shaders/shaderregistry.hpp"
#include "engine/shaders/star_shader.hpp"

#include <memory>
#include <utility>

namespace Engine {
    auto Star::createDefault(const ShaderRegistry& shaderRegistry) -> std::unique_ptr<Entity> {
        auto entity = std::make_unique<Entity>(nullptr, "Star");

        entity->createAndRegisterComponent<Components::StarState>(*entity);

        auto effectComponent = std::make_unique<Components::Effect>(*entity);
        effectComponent->addPreRenderEffect(std::make_unique<Components::Effects::Glow>(*entity));
        entity->registerComponent<Components::Effect>(std::move(effectComponent));

        auto colorGenerator = [entity = entity.get()]([[maybe_unused]] float height) {
            auto& starState = entity->getRequired<Components::StarState>();
            return Star::calculateStarColor(starState.m_temperature);
        };

        auto model = Components::Models::ModelFactory::make<
            Components::Models::Sphere>(*entity, colorGenerator);
        entity->registerComponent<Components::Model>(std::move(model));

        entity->registerComponent<Components::ShaderComponent>(
            std::make_unique<Components::Shaders::GenericShaderComponent>(*entity,
                                                                          shaderRegistry
                                                                              .get<StarShader>()));

        entity->registerComponent<Components::GuiComponent>(
            std::make_unique<Components::Gui::CompositeGui>(*entity));

        entity->createAndRegisterComponent<Components::Transform>(*entity);
        entity->createAndRegisterComponent<Components::Collider>(*entity);

        return entity;
    }

    auto Star::calculateStarColor(int temperature) -> glm::vec3 {
        // Based on
        // https://stackoverflow.com/questions/21977786/star-b-v-color-index-to-apparent-rgb-color
        assert(temperature > 0);

        auto rawTemperatureIndicator = calculateTemperatureIndicator(temperature);
        auto temperatureIndicator    = std::clamp(rawTemperatureIndicator, -0.4f, 2.0f);

        glm::vec3 result;
        double t;

        if (temperatureIndicator < 0.0f) {
            t        = temperatureIndicator / 0.4f + 1.0f;
            result.r = 0.61 + (0.11 * t) + (0.1 * t * t);
        } else if (temperatureIndicator < 0.4f) {
            t        = temperatureIndicator / 0.4f;
            result.r = 0.83 + (0.17 * t);
        } else {
            result.r = 1.00;
        }

        if (temperatureIndicator < 0.0f) {
            t        = temperatureIndicator / 0.4f + 1.0f;
            result.g = 0.70 + (0.07 * t) + (0.1 * t * t);
        } else if (temperatureIndicator < 0.4f) {
            t        = temperatureIndicator / 0.4f;
            result.g = 0.87 + (0.11 * t);
        } else if (temperatureIndicator < 1.6f) {
            t        = (temperatureIndicator - 0.4f) / 1.2f;
            result.g = 0.98 - (0.16 * t);
        } else {
            t        = (temperatureIndicator - 1.60) / 0.4f;
            result.g = 0.82 - (0.5 * t * t);
        }

        if (temperatureIndicator < 0.4f) {
            t        = (temperatureIndicator + 0.40) / 0.8f;
            result.b = 1.00;
        } else if (temperatureIndicator < 1.5f) {
            t        = (temperatureIndicator - 0.40) / 1.1f;
            result.b = 1.00 - (0.47 * t) + (0.1 * t * t);
        } else if (temperatureIndicator < 1.94f) {
            t        = (temperatureIndicator - 1.50) / 0.44f;
            result.b = 0.63 - (0.6 * t * t);
        }

        return result;
    }

    auto Star::calculateTemperatureIndicator(int temperature) -> float {
        assert(temperature > 0);

        auto floatTemperature = static_cast<float>(temperature);

        return (-2.1344 * floatTemperature + 8464 +
                sqrt(0.98724096 * floatTemperature * floatTemperature + 71639296)) /
               (1.6928 * floatTemperature);
    }
}