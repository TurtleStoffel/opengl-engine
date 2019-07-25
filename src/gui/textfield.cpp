#include "gui/textfield.hpp"

#include "opengl.hpp"

namespace gui {

TextField::TextField(GuiObject* pParent) : GuiObject(pParent) {
}

TextField::TextField(GuiObject* pParent, int relX, int relY) : GuiObject(pParent, relX, relY) {
}

void TextField::setContent(std::string content) {
    _content = content;
    // Content has changed, mark parent as dirty so that bounds are recalculated
    _pParent->setDirty();
}

void TextField::getBounds(NVGcontext* vg, float* bounds) {
    // bounds is filled in by nvgTextBounds
    nvgTextBounds(vg, 0, 0, _content.c_str(), nullptr, bounds);
}

void TextField::_renderImplementation(NVGcontext* vg) {
    // Set Text Settings
    nvgFontSize(vg, 15.0f);
    nvgFontFace(vg, "sans");

    // Get height of TextField
    float bounds[4];
    getBounds(vg, bounds);
    float height = bounds[3] - bounds[1];

    // Draw Text
    nvgFillColor(vg, nvgRGBA(0, 0, 0, 255));
    nvgText(vg, 0, height * 0.5f, _content.c_str(), nullptr);
}

}  // namespace gui
