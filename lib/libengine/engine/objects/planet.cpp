#include "engine/objects/planet.hpp"

#include "engine/guibinding/planet_gui.hpp"
#include "engine/models/effects/outline.hpp"
#include "engine/models/model_factory.hpp"
#include "engine/models/sphere.hpp"
#include "engine/objects/collider.hpp"
#include "engine/shaders/lowpolyshader.hpp"
#include "engine/shaders/shaderregistry.hpp"
#include "engine/util.hpp"

#include <math.h>

Planet::Planet(float distance, float radius)
      : Object{nullptr, "Planet"}
      , m_rotationalSpeed{util::randf(0.00003f, 0.0001f)}
      , m_rotationAngle{util::randRadian()}
      , m_distance{distance} {
    m_model = ModelFactory::make<Sphere>(*this);
    m_model->addPreRenderEffect(std::make_unique<Outline>(*m_model.get()));
    m_model->setPreRenderLogic([](const ShaderRegistry& shaderContainer) {
        shaderContainer.get<LowPolyShader>().setSettlementPosition(glm::vec3(0.0f, 0.0f, 1.0f));
    });

    m_guiBinding = std::make_unique<PlanetGui>(*this);

    m_transform->scale(glm::vec3(radius, radius, radius));
    update(0);
}

void Planet::update(int dt) {
    m_rotationAngle += m_rotationalSpeed * dt;
    m_transform->setPosition(
        glm::vec3(m_distance * sin(m_rotationAngle), m_distance * cos(m_rotationAngle), 0.0f));
}