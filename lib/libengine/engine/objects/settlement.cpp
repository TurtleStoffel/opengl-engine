#include "engine/objects/settlement.hpp"

#include "engine/models/settlement_model.hpp"

Settlement::Settlement(const Object* parent, glm::vec3 position) : Object{parent, "Settlement"} {
    model = std::make_unique<SettlementModel>(transform.get());
    transform->translate(position);
}