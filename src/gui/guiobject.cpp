#include "gui/guiobject.hpp"

namespace gui {

GuiObject::GuiObject(int relX, int relY) {
    _relX = relX;
    _relY = relY;
}

void GuiObject::addChild(GuiObject* pChild) {
    _children.push_back(pChild);
}

void GuiObject::_render(NVGcontext* vg) {
    // Push current context state to the stack
    nvgSave(vg);

    // Perform context transformations
    nvgTranslate(vg, _relX, _relY);

    // Call the implementation of the render method
    _renderImplementation(vg);

    // Render child elements
    for (GuiObject* pChild : _children) {
        pChild->_render(vg);
    }

    // Reset context state by popping the stack
    nvgRestore(vg);
}

}  // namespace gui
