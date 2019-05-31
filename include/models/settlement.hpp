#ifndef SETTLEMENT_HPP
#define SETTLEMENT_HPP

#include "models/model.hpp"

class Settlement : public Model {
   public:
    Settlement(Transform* pTransform, Property<bool>* selected);

   private:
};

#endif
