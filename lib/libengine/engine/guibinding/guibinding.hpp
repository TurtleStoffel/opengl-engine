#pragma once

#include <map>
#include <memory>

// Forward declaration to prevent circular imports
class Object;

class GuiBinding {
  public:
    GuiBinding(const Object* pObject);

    void render() const;

  protected:
    const Object* _pObject;
};