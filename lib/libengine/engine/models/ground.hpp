#pragma once

#include "model.hpp"

// TODO Broken because of Indexed Rendering
class Ground : public Model {
  public:
    Ground(Transform* pTransform);

  private:
    const unsigned int _tiles = 32;
    const float _tileSize     = 1.0f;
    const float _noiseFactor  = 0.08f;
    const float _maxHeight    = 2.0f;
};