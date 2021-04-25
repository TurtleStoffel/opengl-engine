#include "engine/objects/planet.hpp"

#include "engine/components/collider.hpp"
#include "engine/components/gui/composite_gui.hpp"
#include "engine/components/gui/planet_gui.hpp"
#include "engine/components/gui_component.hpp"
#include "engine/components/shader_component.hpp"
#include "engine/components/shaders/generic_shader_component.hpp"
#include "engine/models/effects/outline.hpp"
#include "engine/models/model_factory.hpp"
#include "engine/models/sphere.hpp"
#include "engine/shaders/lowpolyshader.hpp"
#include "engine/shaders/shaderregistry.hpp"
#include "engine/util.hpp"

#include <math.h>
#include <utility>

auto Planet::createDefault(float distance, float radius, const ShaderRegistry& shaderRegistry)
    -> std::unique_ptr<Planet> {
    auto planet = std::make_unique<Planet>(distance);

    planet->registerComponent<Engine::Components::ShaderComponent>(
        std::make_unique<Engine::Components::Shaders::GenericShaderComponent>(
            *planet, shaderRegistry.get<LowPolyShader>()));

    auto transform = std::make_unique<Engine::Components::Transform>(*planet);
    transform->scale(glm::vec3{radius, radius, radius});
    planet->registerComponent<Engine::Components::Transform>(std::move(transform));

    planet->registerComponent<Engine::Components::Collider>(
        std::make_unique<Engine::Components::Collider>(*planet));

    auto compositeGui = std::make_unique<Engine::Components::Gui::CompositeGui>(*planet);
    compositeGui->addSubcomponent(std::make_unique<Engine::Components::Gui::PlanetGui>(*planet));
    planet->registerComponent<Engine::Components::GuiComponent>(std::move(compositeGui));

    return planet;
}

Planet::Planet(float distance)
      : Entity{nullptr, "Planet"}
      , m_rotationalSpeed{util::randf(0.00003f, 0.0001f)}
      , m_rotationAngle{util::randRadian()}
      , m_distance{distance} {
    m_model = ModelFactory::make<Engine::Sphere>(*this, &colorGenerator);
    m_model->addPreRenderEffect(std::make_unique<Outline>(*m_model.get()));
}

auto Planet::colorGenerator(float height) -> glm::vec3 {
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