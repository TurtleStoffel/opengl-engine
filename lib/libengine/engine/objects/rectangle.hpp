#include "engine/objects/object.hpp"

class Rectangle : public Object {
  public:
    Rectangle(const Object* parent, glm::vec3 position);
};