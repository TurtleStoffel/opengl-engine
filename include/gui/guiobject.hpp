#ifndef GUIOBJECT_HPP
#define GUIOBJECT_HPP

#include "nanovg.h"

#include <vector>

namespace gui {

class GuiObject {
    friend class Gui;

   public:
    /**
     * Construct GUI Object where Top left is x and y relative to Parent Top Left, if Parent is
     * null, x and y are absolute coordinates
     */
    GuiObject(int relX, int relY);
    virtual ~GuiObject();

    void addChild(GuiObject* pChild);

   protected:
    /**
     * Perform the rendering of the component itself
     */
    virtual void _renderImplementation(NVGcontext* vg) = 0;

   private:
    /**
     * Manage state and call rendering implementations
     * 1. Push current context state to the stack
     * 2. Execute transformations
     * 3. Call _renderImplementation
     * 4. Call _render from child elements
     * 5. Pop context state from the stack
     */
    void _render(NVGcontext* vg);

    int _relX;
    int _relY;

    std::vector<GuiObject*> _children;
};

}  // namespace gui

#endif
