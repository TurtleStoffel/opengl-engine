#include "engine/objects/planet.hpp"

#include "engine/color.hpp"
#include "engine/components/collider.hpp"
#include "engine/components/color_selector.hpp"
#include "engine/components/effect.hpp"
#include "engine/components/gui/composite_gui.hpp"
#include "engine/components/gui/planet_gui.hpp"
#include "engine/components/gui_component.hpp"
#include "engine/components/models/model_factory.hpp"
#include "engine/components/models/sphere.hpp"
#include "engine/components/shader_component.hpp"
#include "engine/components/shaders/generic_shader_component.hpp"
#include "engine/models/effects/outline.hpp"
#include "engine/noise/simplex_noise.hpp"
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

        planet->createAndRegisterComponent<Components::Collider>(*planet);

        auto compositeGui = std::make_unique<Components::Gui::CompositeGui>(*planet);
        compositeGui->addSubcomponent(std::make_unique<Components::Gui::PlanetGui>(*planet));
        planet->registerComponent<Components::GuiComponent>(std::move(compositeGui));

        planet->createAndRegisterComponent<Components::ColorSelector>(*planet);

        return planet;
    }

    Planet::Planet(float distance)
          : Entity{nullptr, "Planet"}
          , m_rotationalSpeed{util::randf(0.00003f, 0.0001f)}
          , m_rotationAngle{util::randRadian()}
          , m_distance{distance} {

        auto colorFunction = [this](float height) {
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
        auto noiseFunction = [](glm::vec3& point) {
            float noise = SimplexNoise::noise(point.x * 2.0f, point.y * 2.0f, point.z * 2.0f);
            // Noise in range [0, 1]
            auto normalizedHeight = (noise + 1.0f) / 2.0f;

            auto heightFactor = 1.0f + noise / 15.0f;
            point *= heightFactor;
            return normalizedHeight;
        };
        createAndRegisterComponent<Components::Effect>(*this);
        auto model = Components::Models::ModelFactory::make<
            Components::Models::Sphere>(*this, colorFunction, noiseFunction);
        model->addPreRenderEffect(std::make_unique<Outline>(*model));
        registerComponent<Components::Model>(std::move(model));
    }
}