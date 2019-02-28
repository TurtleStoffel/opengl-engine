#ifndef GUI_HPP
#define GUI_HPP

#include <vector>

#include "nanovg.h"
#include "opengl.hpp"

#include "gui/guiobject.hpp"

namespace gui {

class Gui {
   public:
    Gui(SDL_Window* pWindow);
    ~Gui();

    void render();

   private:
    SDL_Window* _pWindow;
    NVGcontext* _vg;

    std::vector<GuiObject*> _children;
};

}  // namespace gui

#endif
