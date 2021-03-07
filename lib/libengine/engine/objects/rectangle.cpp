#include "engine/objects/rectangle.hpp"

#include "engine/models/model_factory.hpp"
#include "engine/models/rectangle_model.hpp"
#include "engine/shaders/circleshader.hpp"
#include "engine/shaders/shadercontainer.hpp"

#include <glm/glm.hpp>

Rectangle::Rectangle() : Object{nullptr, "Rectangle"} {
    model = ModelFactory::make<RectangleModel>(*this);
    transform->translate(glm::vec3(1.2f, 0.2f, 0.0f));
    transform->scale(glm::vec3(3.0f, 3.0f, 1.0f));
    model->setPreRenderLogic([&transform = transform](const ShaderRegistry& shaderContainer) {
        shaderContainer.get<CircleShader>().use();
        shaderContainer.get<CircleShader>().setCirclePosition(transform->getPosition());
    });
}