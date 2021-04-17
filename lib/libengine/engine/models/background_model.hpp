#pragma once

#include "engine/models/model.hpp"

namespace Engine {
    class Entity;
}

class BackgroundModel : public Model {
  public:
    BackgroundModel(const Engine::Entity& object);
};