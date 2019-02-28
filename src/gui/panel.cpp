#include "gui/panel.hpp"

#include "nanovg.h"

namespace gui {

Panel::Panel(GuiObject* pParent, int relX, int relY) : GuiObject(pParent, relX, relY) {
}

void Panel::_render(NVGcontext* vg) {
    // Draw Rectangle
    nvgBeginPath(vg);
    nvgRect(vg, _getAbsoluteX(), _getAbsoluteY(), _minWidth, _minHeight);
    nvgFillColor(vg, nvgRGBA(255, 192, 0, 255));
    nvgFill(vg);

    /* Stefan Wauters
     * Use this as reference for when Textfield gets added to GUI (GW-80)
    // Set Text Settings
    nvgFontSize(_vg, 30.0f);
    nvgFontFace(_vg, "sans");
    nvgTextAlign(_vg, NVG_ALIGN_LEFT | NVG_ALIGN_MIDDLE);

    // Draw Text
    nvgFillColor(_vg, nvgRGBA(255, 255, 255, 255));
    nvgText(_vg, x + 5, y + h / 2, "test", NULL);
    */
}

void Panel::setMinWidth(int minWidth) {
    _minWidth = minWidth;
}

void Panel::setMinHeight(int minHeight) {
    _minHeight = minHeight;
}

}  // namespace gui
