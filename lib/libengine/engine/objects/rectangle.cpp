#include "engine/objects/rectangle.hpp"

#include "engine/models/model_factory.hpp"
#include "engine/models/rectangle_model.hpp"

Rectangle::Rectangle(const Object* parent, glm::vec3 position) : Object{parent, "Rectangle"} {
    model = ModelFactory::make<RectangleModel>(*this);
    transform->translate(position);
}