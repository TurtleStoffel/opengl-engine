#pragma once

#include "engine/models/model.hpp"

namespace Engine {
    class Object;
}

class BackgroundModel : public Model {
  public:
    BackgroundModel(const Engine::Object& object);
};