#include "listview.hpp"

namespace gui {

Bounds ListView::loadBounds(NVGcontext* vg) {
    nvgSave(vg);
    nvgTranslate(vg, _relX, _relY);

    _bounds = Bounds();
    for (std::unique_ptr<GuiObject>& pChild : _children) {
        _bounds.contain(pChild->loadBounds(vg));
    }

    nvgRestore(vg);

    return _bounds;
}

void ListView::_renderImplementation(NVGcontext* vg) {
    nvgFontSize(vg, 17.0f);
    nvgFontFace(vg, "sans");

    loadBounds(vg);

    nvgBeginPath(vg);
    nvgRect(vg, 0, 0, _bounds.getWidth() + 2 * _relX, _bounds.getHeight() + 2 * _relY);
    nvgFillColor(vg, nvgRGBA(43, 45, 52, 200));
    nvgFill(vg);
}

} // namespace gui