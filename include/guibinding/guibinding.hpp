#ifndef GUIBINDING_HPP
#define GUIBINDING_HPP

#include <map>
#include <memory>

#include "gui/gui.hpp"
#include "gui/textfield.hpp"

// Forward declaration to prevent circular imports
class Object;

class GuiBinding {
   public:
    GuiBinding(const Object* pObject);
    virtual ~GuiBinding();

    void changeSelected(bool selected);

   protected:
    const Object* _pObject;

    /**
     * Shared between the GUI and the GuiBinding Object
     * Reason it is not unique_ptr is because we want to keep the GuiBinding in memory as long as
     * the object it is linked to exists. if the Panel is passed to the GUI as unique_ptr it will be
     * destroyed once it is replaced with a different panel.
     */
    std::shared_ptr<gui::Panel> _pPanel;
};

#endif
