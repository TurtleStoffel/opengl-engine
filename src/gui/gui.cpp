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
    if (nvgCreateFont(_vg, "sans", "../res/Roboto-Regular.ttf") == -1) {
        SDL_Log("Could not open font");
    }

    // Create Parent Panel
    Panel* testPanel = new Panel(50, 50);
    testPanel->setMinWidth(200);
    testPanel->setMinHeight(50);

    // Create Child Panel
    Panel* testPanel2 = new Panel(20, 20);
    testPanel2->setMinWidth(120);
    testPanel2->setMinHeight(20);

    // Create Textfield to add to Child Panel
    TextField* textField = new TextField(5, 5);
    textField->setContent("Some Text");

    testPanel2->addChild(textField);

    testPanel->addChild(testPanel2);

    _children.push_back(testPanel);
}

Gui::~Gui() {
    nvgDeleteGL3(_vg);

    for (GuiObject* child : _children) {
        delete child;
    }
}

void Gui::render() {
    // Begin NanoVG Frame, ratio is always 1.0f if not a High DPI Screen
    nvgBeginFrame(_vg, _windowWidth, _windowHeight, 1.0f);

    // Save NanoVG State
    nvgSave(_vg);

    for (GuiObject* guiObject : _children) {
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

}  // namespace gui
