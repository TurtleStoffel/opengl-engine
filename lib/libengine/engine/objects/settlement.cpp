#include "settlement.hpp"

#include "models/settlement_model.hpp"

Settlement::Settlement(Object* parent, glm::vec3 position) : Object(parent) {
    model = std::make_unique<SettlementModel>(transform.get());
    transform->translate(position);
}