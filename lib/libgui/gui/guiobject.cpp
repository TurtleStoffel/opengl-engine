#include "guiobject.hpp"

namespace gui {

GuiObject::GuiObject() : GuiObject(_DEFAULT_X_OFFSET, _DEFAULT_Y_OFFSET) {
}

GuiObject::GuiObject(int relX, int relY) {
    _relX = relX;
    _relY = relY;
}

GuiObject::~GuiObject() {
    // Empty virtual destructor
}

void GuiObject::addChild(std::unique_ptr<GuiObject> pChild) {
    _children.push_back(std::move(pChild));
}

void GuiObject::_render(NVGcontext* vg) {
    // Push current context state to the stack
    nvgSave(vg);

    // Perform context transformations
    nvgTranslate(vg, _relX, _relY);

    // Make sure bounds are recalculated if an element is marked dirty
    loadBounds(vg);

    // Call the implementation of the render method (is implemented by each type of GUI Object)
    _renderImplementation(vg);

    // Render child elements
    for (std::unique_ptr<GuiObject>& pChild : _children) {
        pChild->_render(vg);
        Bounds childBounds = pChild->loadBounds(vg);
        nvgTranslate(vg, 0, childBounds.getHeight());
    }

    // Reset context state by popping the stack
    nvgRestore(vg);
}

} // namespace gui
