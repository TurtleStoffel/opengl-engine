#ifndef SETTLEMENT_HPP
#define SETTLEMENT_HPP

#include "models/model.hpp"

// TODO Broken because of Indexed Rendering
class Settlement : public Model {
   public:
    Settlement(Transform* pTransform, Property<bool>* selected);

   private:
};

#endif
