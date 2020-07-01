#pragma once

#include <memory>
#include <vector>

#include "nanovg.h"

#include "bounds.hpp"

namespace gui {

class GuiObject {
    friend class Gui;

  public:
    /**
     * Top Left corner is offset using the defaults from Top Left of parent object ((0, 0) if no
     * Parent)
     */
    GuiObject();
    /**
     * Top Left corner is offset using the defaults from Top Left of parent object ((0, 0) if no
     * Parent)
     */
    GuiObject(int relX, int relY);
    virtual ~GuiObject();

    void addChild(std::unique_ptr<GuiObject> pChild);

    virtual Bounds loadBounds(NVGcontext* vg) = 0;

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

    // if true, recalculate bounds on next render
    bool _dirty = true;

    // GUI Hierarchy elements
    std::vector<std::unique_ptr<GuiObject>> _children;

  protected:
    Bounds _bounds;

    int _relX;
    int _relY;

  private:
    static const int _DEFAULT_X_OFFSET = 15;
    static const int _DEFAULT_Y_OFFSET = 15;
};

} // namespace gui