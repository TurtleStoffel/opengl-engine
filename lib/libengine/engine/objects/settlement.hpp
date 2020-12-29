#include "object.hpp"

class Settlement : public Object {
  public:
    Settlement(const Object* parent, glm::vec3 position);
};