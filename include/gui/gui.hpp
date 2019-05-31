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
    /**
     * Clear all information currently in the GUI and add pPanel.
     * if pPanel == null, the GUI is cleared
     */
    void setSelectedPanel(Panel* pPanel);

   private:
    NVGcontext* _vg;

    int _windowWidth;
    int _windowHeight;

    std::vector<GuiObject*> _children;
};

}  // namespace gui

#endif
