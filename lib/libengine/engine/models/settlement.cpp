#include "settlement.hpp"

#include "square.hpp"

Settlement::Settlement(Transform* pTransform, Property<bool>* selected)
    : Model(pTransform, selected) {
}