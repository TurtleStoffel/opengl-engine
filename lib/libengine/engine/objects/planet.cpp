#include "engine/objects/planet.hpp"

#include "engine/components/shader_component.hpp"
#include "engine/components/shaders/generic_shader_component.hpp"
#include "engine/guibinding/planet_gui.hpp"
#include "engine/models/effects/outline.hpp"
#include "engine/models/model_factory.hpp"
#include "engine/models/sphere.hpp"
#include "engine/objects/collider.hpp"
#include "engine/shaders/lowpolyshader.hpp"
#include "engine/shaders/shaderregistry.hpp"
#include "engine/util.hpp"

#include <math.h>
#include <utility>

auto Planet::createDefault(float distance, float radius, const ShaderRegistry& shaderRegistry)
    -> std::unique_ptr<Planet> {
    auto planet = std::make_unique<Planet>(distance, radius);

    planet->registerComponent<Engine::Components::ShaderComponent>(
        std::make_unique<Engine::Components::Shaders::GenericShaderComponent>(
            *planet, shaderRegistry.get<LowPolyShader>()));

    return planet;
}

Planet::Planet(float distance, float radius)
      : Object{nullptr, "Planet"}
      , m_rotationalSpeed{util::randf(0.00003f, 0.0001f)}
      , m_rotationAngle{util::randRadian()}
      , m_distance{distance} {
    auto colorGenerator = []([[maybe_unused]] const glm::vec3& position) { return color::brown; };
    m_model             = ModelFactory::make<Engine::Sphere>(*this, colorGenerator);
    m_model->addPreRenderEffect(std::make_unique<Outline>(*m_model.get()));

    m_guiBinding = std::make_unique<PlanetGui>(*this);

    m_transform->scale(glm::vec3(radius, radius, radius));
    update(0);
}