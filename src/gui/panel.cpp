#include "gui/panel.hpp"

#include "nanovg.h"

namespace gui {

Panel::Panel() : GuiObject() {
}

Panel::Panel(int relX, int relY) : GuiObject(relX, relY) {
}

void Panel::_renderImplementation(NVGcontext* vg) {
    // Draw Rectangle
    nvgBeginPath(vg);
    nvgRect(vg, 0, 0, _minWidth, _minHeight);
    nvgFillColor(vg, nvgRGBA(255, 192, 0, 255));
    nvgFill(vg);

    nvgBeginPath(vg);
    nvgRect(vg, 0, 0, _minWidth, _minHeight);
    nvgStrokeColor(vg, nvgRGBA(0, 0, 0, 255));
    nvgStroke(vg);
}

void Panel::setMinWidth(int minWidth) {
    _minWidth = minWidth;
}

void Panel::setMinHeight(int minHeight) {
    _minHeight = minHeight;
}

}  // namespace gui
