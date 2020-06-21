#pragma once

#include "model.hpp"

class Settlement : public Model {
  public:
    Settlement(Transform* pTransform, Property<bool>* selected);
};