#include "engine/objects/settlement.hpp"

#include "engine/models/model_factory.hpp"
#include "engine/models/settlement_model.hpp"

Settlement::Settlement(const Object* parent, glm::vec3 position) : Object{parent, "Settlement"} {
    model = ModelFactory::make<SettlementModel>(transform.get());
    transform->translate(position);
}