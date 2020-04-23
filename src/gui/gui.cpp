#include "gui/gui.hpp"

#define NANOVG_GL3_IMPLEMENTATION
#include "nanovg_gl.h"

#include "const.hpp"
#include "gui/panel.hpp"
#include "gui/textfield.hpp"

namespace gui {

Gui::Gui() {
    // Create rendering context
    _vg = nvgCreateGL3(NVG_ANTIALIAS);

    // Set initial buffer and window sizes
    _windowWidth  = constant::initialWindowWidth;
    _windowHeight = constant::initialWindowHeight;

    // Initialise font
    if (nvgCreateFont(_vg, "sans", "res/Roboto-Regular.ttf") == -1) {
        SDL_Log("Could not open font");
    }
}

Gui::~Gui() {
    nvgDeleteGL3(_vg);
}

void Gui::render() {
    // Begin NanoVG Frame, ratio is always 1.0f if not a High DPI Screen
    nvgBeginFrame(_vg, _windowWidth, _windowHeight, 1.0f);

    // Save NanoVG State
    nvgSave(_vg);

    for (std::shared_ptr<GuiObject> guiObject : _children) {
        guiObject->_render(_vg);
    }

    // Reset NanoVG State
    nvgRestore(_vg);

    nvgEndFrame(_vg);

    // Restore variables edited by NanoVG
    glDisable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
}

void Gui::setWindowParameters(int windowWidth, int windowHeight) {
    _windowWidth  = windowWidth;
    _windowHeight = windowHeight;
}

void Gui::setSelectedPanel(std::shared_ptr<Panel> pPanel) {
    // Clear _children list, Objects that added them are responsible for freeing the memory!
    _children.clear();

    // Only add panel if it is not a nullptr
    if (pPanel) {
        _children.push_back(pPanel);
    }
}

} // namespace gui
