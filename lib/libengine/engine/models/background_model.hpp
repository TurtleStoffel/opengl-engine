#pragma once

#include "engine/models/model.hpp"

class Object;

class BackgroundModel : public Model {
  public:
    BackgroundModel(const Object& object);
};