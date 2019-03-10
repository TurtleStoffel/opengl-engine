#ifndef GUIOBJECT_HPP
#define GUIOBJECT_HPP

#include "nanovg.h"

#include <vector>

namespace gui {

class GuiObject {
    friend class Gui;

   public:
    /**
     * Top Left corner is offset using the defaults from Top Left of parent object. If parent is
     * nullptr, x and y are absolute coordinates
     */
    GuiObject();
    /**
     * Top Left corner is offset x and y relative to Top Left of parent object. If parent is
     * nullptr, x and y are absolute coordinates
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
    static const int _DEFAULT_X_OFFSET = 5;
    static const int _DEFAULT_Y_OFFSET = 5;

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
