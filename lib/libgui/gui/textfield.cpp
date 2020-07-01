#include "textfield.hpp"

namespace gui {

void TextField::setContent(std::string content) {
    _content = content;
    // Mark as dirty so that bounds are recalculated
    _dirty = true;
}

Bounds TextField::loadBounds(NVGcontext* vg) {
    nvgSave(vg);
    nvgTranslate(vg, _relX, _relY);

    float bounds[4];
    nvgTextBounds(vg, 0, 0, _content.c_str(), nullptr, bounds);
    _bounds = Bounds(bounds);

    nvgRestore(vg);

    return _bounds;
}

void TextField::_renderImplementation(NVGcontext* vg) {
    // Set Text Settings
    nvgFontSize(vg, 15.0f);
    nvgFontFace(vg, "sans");

    // Get height of TextField
    loadBounds(vg);

    // Draw Text
    nvgFillColor(vg, nvgRGBA(255, 255, 255, 255));
    nvgText(vg, 0, _bounds.getHeight() * 0.5f, _content.c_str(), nullptr);
}

} // namespace gui
