#include "engine/objects/rectangle.hpp"

#include "engine/models/model_factory.hpp"
#include "engine/models/rectangle_model.hpp"
#include "engine/shaders/shadercontainer.hpp"

Rectangle::Rectangle() : Object{nullptr, "Rectangle"} {
    model = ModelFactory::make<RectangleModel>(*this);
    model->setPreRenderLogic([&transform = transform](const ShaderContainer& shaderContainer) {
        shaderContainer.circleShader().setCirclePosition(transform->getPosition());
        shaderContainer.circleShader().use();
    });
}