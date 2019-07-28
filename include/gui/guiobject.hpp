#ifndef GUIOBJECT_HPP
#define GUIOBJECT_HPP

#include "nanovg.h"

#include <memory>
#include <vector>

namespace gui {

class GuiObject {
    friend class Gui;

   public:
    /**
     * Top Left corner is offset using the defaults from Top Left of parent object. If parent is
     * nullptr, x and y are 0 (top left)
     */
    GuiObject(GuiObject* pParent);
    /**
     * Top Left corner is offset x and y relative to Top Left of parent object. If parent is
     * nullptr, x and y are absolute coordinates
     */
    GuiObject(GuiObject* pParent, int relX, int relY);
    virtual ~GuiObject();

    void addChild(std::unique_ptr<GuiObject> pChild);
    /**
     * Set this GUI element as dirty to recalculate bounds on next render
     */
    void markDirty();
    virtual void calculateBounds(NVGcontext* vg);

    /**
     * parameter bounds should be a pointer to float[4]. Return with format [xmin, ymin, xmax, ymax]
     */
    virtual void getBounds(NVGcontext* vg, float* bounds) = 0;

   protected:
    /**
     * Perform the rendering of the component itself
     */
    virtual void _renderImplementation(NVGcontext* vg) = 0;

    /**
     * Manage state and call rendering implementations
     * 1. Push current context state to the stack
     * 2. Execute transformations
     * 3. Call _renderImplementation
     * 4. Call _render from child elements
     * 5. Pop context state from the stack
     */
    void _render(NVGcontext* vg);

    // if dirty == true, recalculate bounds on next render because this element or some element
    // lower in the hierarchy changed
    bool _dirty = false;

    // GUI Hierarchy elements
    GuiObject* _pParent;
    std::vector<std::unique_ptr<GuiObject>> _children;

   private:
    static const int _DEFAULT_X_OFFSET = 5;
    static const int _DEFAULT_Y_OFFSET = 5;

    int _relX;
    int _relY;
};

}  // namespace gui

#endif
