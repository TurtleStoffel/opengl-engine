#ifndef GUI_HPP
#define GUI_HPP

#include "nanovg.h"
#include "opengl.hpp"

class Gui {
   public:
    Gui(SDL_Window* pWindow);
    ~Gui();

    void render();

   private:
    SDL_Window* _pWindow;
    NVGcontext* _vg;
};

#endif
