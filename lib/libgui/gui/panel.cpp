#include "panel.hpp"

#include "nanovg.h"

namespace gui {

Bounds Panel::loadBounds(NVGcontext* vg) {
    nvgSave(vg);
    nvgTranslate(vg, _relX, _relY);

    _bounds = Bounds();
    for (std::unique_ptr<GuiObject>& pChild : _children) {
        _bounds.contain(pChild->loadBounds(vg));
    }

    nvgRestore(vg);

    return _bounds;
}

void Panel::_renderImplementation(NVGcontext* vg) {
    // Draw Rectangle
    nvgBeginPath(vg);
    nvgRect(vg, 0, 0, _bounds.getWidth() + 2 * _relX, _bounds.getHeight() + 2 * _relY);
    nvgFillColor(vg, nvgRGBA(43, 45, 52, 200));
    nvgFill(vg);

    // Draw Black Border
    nvgBeginPath(vg);
    nvgRect(vg, 0, 0, _bounds.getWidth() + 2 * _relX, _bounds.getHeight() + 2 * _relY);
    nvgStrokeColor(vg, nvgRGBA(0, 0, 0, 255));
    nvgStroke(vg);
}

} // namespace gui
