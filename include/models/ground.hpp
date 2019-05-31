#ifndef GROUND_HPP
#define GROUND_HPP

#include "models/model.hpp"

class Ground : public Model {
   public:
    Ground(Transform* pTransform, Property<bool>* selected);

   private:
    const unsigned int _tiles = 32;
    const float _tileSize     = 1.0f;
    const float _noiseFactor  = 0.08f;
    const float _maxHeight    = 2.0f;
};

#endif
