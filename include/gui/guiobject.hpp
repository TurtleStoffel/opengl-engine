#ifndef GUIOBJECT_HPP
#define GUIOBJECT_HPP

#include "nanovg.h"

namespace gui {

class GuiObject {
    friend class Gui;

   public:
    /**
     * Construct GUI Object where Top left is x and y relative to Parent Top Left, if Parent is
     * null, x and y are absolute coordinates
     */
    GuiObject(GuiObject* pParent, int relX, int relY);

   protected:
    virtual void _render(NVGcontext* vg) = 0;
    int _getAbsoluteX();
    int _getAbsoluteY();

   private:
    GuiObject* _pParent;

    int _relX;
    int _relY;
};

}  // namespace gui

#endif
