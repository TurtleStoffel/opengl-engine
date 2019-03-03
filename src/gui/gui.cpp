#include "gui/gui.hpp"

#define NANOVG_GL3_IMPLEMENTATION
#include "nanovg_gl.h"

#include "camera.hpp"
#include "gui/panel.hpp"

namespace gui {

Gui::Gui(SDL_Window* pWindow) {
    _pWindow = pWindow;
    _vg      = nvgCreateGL3(NVG_ANTIALIAS);

    // Initialise font
    if (nvgCreateFont(_vg, "sans", "../res/Roboto-Regular.ttf") == -1) {
        SDL_Log("Could not open font");
    }

    Panel* testPanel = new Panel(50, 50);
    testPanel->setMinWidth(120);
    testPanel->setMinHeight(30);

    _children.push_back(testPanel);
}

Gui::~Gui() {
    nvgDeleteGL3(_vg);
}

void Gui::render() {
    // Get window Size for to start NanoVG frame
    int bufferWidth;
    int bufferHeight;
    SDL_GL_GetDrawableSize(_pWindow, &bufferWidth, &bufferHeight);

    int windowWidth;
    int windowHeight;
    Camera::instance()->getWindowSize(windowWidth, windowHeight);
    nvgBeginFrame(_vg, windowWidth, windowHeight, (float)bufferWidth / windowHeight);

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

}  // namespace gui
