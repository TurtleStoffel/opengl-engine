#include "gui/guiobject.hpp"

namespace gui {

GuiObject::GuiObject(GuiObject* pParent, int relX, int relY) {
    _pParent = pParent;
    _relX    = relX;
    _relY    = relY;
}

int GuiObject::_getAbsoluteX() {
    int offset = _pParent ? _pParent->_getAbsoluteX() : 0;
    return _relX + offset;
}

int GuiObject::_getAbsoluteY() {
    int offset = _pParent ? _pParent->_getAbsoluteY() : 0;
    return _relY + offset;
}

}  // namespace gui
