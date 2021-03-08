#include "engine/objects/rectangle.hpp"

#include "engine/models/model_factory.hpp"
#include "engine/models/rectangle_model.hpp"
#include "engine/shaders/circleshader.hpp"
#include "engine/shaders/shaderregistry.hpp"

#include <glm/glm.hpp>

Rectangle::Rectangle() : Object{nullptr, "Rectangle"} {
    m_model = ModelFactory::make<RectangleModel>(*this);
    m_transform->translate(glm::vec3(1.2f, 0.2f, 0.0f));
    m_transform->scale(glm::vec3(3.0f, 3.0f, 1.0f));
    m_model->setPreRenderLogic([&transform = m_transform](const ShaderRegistry& shaderContainer) {
        shaderContainer.get<CircleShader>().use();
        shaderContainer.get<CircleShader>().setCirclePosition(transform->getPosition());
    });
}