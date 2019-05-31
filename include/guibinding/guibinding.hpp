#ifndef GUIBINDING_HPP
#define GUIBINDING_HPP

#include "gui/gui.hpp"

// Forward declaration to prevent circular imports
class Object;

class GuiBinding {
   public:
    GuiBinding(Object* pObject);
    virtual ~GuiBinding();

    virtual void render() = 0;

    void changeSelected(bool selected);

   protected:
    Object* _pObject;
    gui::Panel* _pPanel;
};

#endif
