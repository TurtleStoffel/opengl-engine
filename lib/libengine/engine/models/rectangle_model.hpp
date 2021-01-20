#pragma once

#include "engine/models/model.hpp"

class Object;

class RectangleModel : public Model {
  public:
    RectangleModel(const Object& object);
};