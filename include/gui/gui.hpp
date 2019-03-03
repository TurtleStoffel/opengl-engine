#ifndef GUI_HPP
#define GUI_HPP

#include <vector>

#include "nanovg.h"
#include "opengl.hpp"

#include "gui/guiobject.hpp"

namespace gui {

class Gui {
   public:
    Gui();
    ~Gui();

    void render();

    void setWindowParameters(int windowWidth, int windowHeight);

   private:
    NVGcontext* _vg;

    int _windowWidth;
    int _windowHeight;

    std::vector<GuiObject*> _children;
};

}  // namespace gui

#endif
