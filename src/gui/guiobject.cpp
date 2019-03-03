#include "gui/guiobject.hpp"

namespace gui {

GuiObject::GuiObject(GuiObject* pParent, int relX, int relY) {
    _pParent = pParent;
    _relX    = relX;
    _relY    = relY;
}

void GuiObject::_render(NVGcontext* vg) {
    // Push current context state to the stack
    nvgSave(vg);

    // Perform context transformations
    nvgTranslate(vg, _relX, _relY);

    // Call the implementation of the render method
    _renderImplementation(vg);

    // Reset context state by popping the stack
    nvgRestore(vg);
}

}  // namespace gui
