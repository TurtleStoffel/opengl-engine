#ifndef GROUND_HPP
#define GROUND_HPP

#include "models/model.hpp"

class Ground : public Model {
   public:
    Ground();

   private:
    const unsigned int _tiles = 16;
    const float _tileSize = 1.0f;
};

#endif
