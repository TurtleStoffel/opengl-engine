#include "object.hpp"

class Settlement : public Object {
  public:
    Settlement(Object* parent, glm::vec3 position);
};