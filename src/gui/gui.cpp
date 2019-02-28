#include "gui/gui.hpp"

#define NANOVG_GL3_IMPLEMENTATION
#include "nanovg_gl.h"

#include <iostream>

#include "camera.hpp"

Gui::Gui(SDL_Window* pWindow) {
    _pWindow = pWindow;
    _vg      = nvgCreateGL3(NVG_ANTIALIAS);

    // Initialise font
    if (nvgCreateFont(_vg, "sans", "../res/Roboto-Regular.ttf") == -1) {
        std::cout << "could not open font" << std::endl;
    }
}

Gui::~Gui() {
    nvgDeleteGL3(_vg);
}

void Gui::render() {
    // Render GUI
    int x = 50;
    int y = 50;
    int w = 120;
    int h = 30;

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

    // Draw Rectangle
    nvgBeginPath(_vg);
    nvgRect(_vg, x, y, w, h);
    nvgFillColor(_vg, nvgRGBA(255, 192, 0, 255));
    nvgFill(_vg);

    // Set Text Settings
    nvgFontSize(_vg, 30.0f);
    nvgFontFace(_vg, "sans");
    nvgTextAlign(_vg, NVG_ALIGN_LEFT | NVG_ALIGN_MIDDLE);

    // Draw Text
    nvgFillColor(_vg, nvgRGBA(255, 255, 255, 255));
    nvgText(_vg, x + 5, y + h / 2, "test", NULL);

    // Reset NanoVG State
    nvgRestore(_vg);

    nvgEndFrame(_vg);

    // Restore variables edited by NanoVG
    glDisable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
}
