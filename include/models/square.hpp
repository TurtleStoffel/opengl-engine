#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "models/model.hpp"

class Square : public Model {
   public:
    Square(Transform* pTransform, Property<bool>* selected);
};

#endif
