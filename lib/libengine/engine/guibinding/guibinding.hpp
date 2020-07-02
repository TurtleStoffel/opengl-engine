#pragma once

#include <map>
#include <memory>

// Forward declaration to prevent circular imports
class Object;

class GuiBinding {
  public:
    GuiBinding(const Object* pObject);
    virtual ~GuiBinding();

    void changeSelected(bool selected);

  protected:
    const Object* _pObject;
};