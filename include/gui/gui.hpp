#ifndef GUI_HPP
#define GUI_HPP

#include <vector>

#include "nanovg.h"
#include "opengl.hpp"

#include "gui/guiobject.hpp"
#include "gui/panel.hpp"

namespace gui {

class Gui {
   public:
    Gui();
    ~Gui();

    void render();

    void setWindowParameters(int windowWidth, int windowHeight);
    void setSelectedPanel(Panel* pPanel);

   private:
    void _clearChildren();

    NVGcontext* _vg;

    int _windowWidth;
    int _windowHeight;

    std::vector<GuiObject*> _children;
};

}  // namespace gui

#endif
