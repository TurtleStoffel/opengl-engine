#include "gui/guiobject.hpp"

namespace gui {

GuiObject::GuiObject(GuiObject* pParent)
    : GuiObject(pParent, _DEFAULT_X_OFFSET, _DEFAULT_Y_OFFSET) {
}

GuiObject::GuiObject(GuiObject* pParent, int relX, int relY) {
    _pParent = pParent;
    _relX    = relX;
    _relY    = relY;
}

GuiObject::~GuiObject() {
    // Empty virtual destructor
}

void GuiObject::addChild(std::unique_ptr<GuiObject> pChild) {
    _children.push_back(std::move(pChild));
}

void GuiObject::setDirty() {
    _dirty = true;

    if (_pParent) {
        _pParent->setDirty();
    }
}

void GuiObject::calculateBounds(NVGcontext* vg) {
    // Default implementation is that nothing happens (Text does not change in the hierarchy, the
    // panel that contains the text will
}

void GuiObject::_render(NVGcontext* vg) {
    // Push current context state to the stack
    nvgSave(vg);

    // Perform context transformations
    nvgTranslate(vg, _relX, _relY);

    // If element is marked dirty, recalculate bounds
    if (_dirty) {
        calculateBounds(vg);
    }

    // Call the implementation of the render method (is implemented by each type of GUI Object)
    _renderImplementation(vg);

    // Render child elements
    for (std::unique_ptr<GuiObject>& pChild : _children) {
        pChild->_render(vg);
        float bounds[4];
        pChild->getBounds(vg, bounds);
        nvgTranslate(vg, 0, bounds[3] - bounds[1]);
    }

    // Reset context state by popping the stack
    nvgRestore(vg);
}

}  // namespace gui
