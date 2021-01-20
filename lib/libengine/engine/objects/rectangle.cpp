#include "engine/objects/rectangle.hpp"

#include "engine/models/model_factory.hpp"
#include "engine/models/rectangle_model.hpp"

Rectangle::Rectangle() : Object{nullptr, "Rectangle"} {
    model = ModelFactory::make<RectangleModel>(*this);
}