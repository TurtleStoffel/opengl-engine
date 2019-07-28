#include "gui/panel.hpp"

#include "nanovg.h"

namespace gui {

Panel::Panel(GuiObject* pParent) : GuiObject(pParent) {
}

Panel::Panel(GuiObject* pParent, int relX, int relY) : GuiObject(pParent, relX, relY) {
}

void Panel::setWidth(int width) {
    _width = width;
}

void Panel::setHeight(int height) {
    _height = height;
}

void Panel::getBounds(NVGcontext* vg, float* bounds) {
    bounds[0] = 0.0f;
    bounds[1] = 0.0f;
    bounds[2] = 0.0f;
    bounds[3] = 0.0f;

    for (std::unique_ptr<GuiObject>& pChild : _children) {
        float childBounds[4];
        pChild->getBounds(vg, childBounds);
        // By default use vertical stacking
        // take min/max for x
        if (childBounds[0] < bounds[0]) {
            bounds[0] = childBounds[0];
        }
        if (childBounds[2] > bounds[2]) {
            bounds[2] = childBounds[2];
        }

        // add y coordinates together
        bounds[3] += childBounds[3] - childBounds[1];
    }
}

void Panel::calculateBounds(NVGcontext* vg) {
    float bounds[4];
    getBounds(vg, bounds);
    _width  = bounds[2] - bounds[0];
    _height = bounds[3] - bounds[1];
}

void Panel::_renderImplementation(NVGcontext* vg) {
    // Draw Rectangle
    nvgBeginPath(vg);
    nvgRect(vg, 0, 0, _width, _height);
    nvgFillColor(vg, nvgRGBA(255, 192, 0, 255));
    nvgFill(vg);

    // Draw Black Border
    nvgBeginPath(vg);
    nvgRect(vg, 0, 0, _width, _height);
    nvgStrokeColor(vg, nvgRGBA(0, 0, 0, 255));
    nvgStroke(vg);
}

}  // namespace gui
