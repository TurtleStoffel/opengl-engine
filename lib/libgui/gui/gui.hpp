#pragma once

#include <memory>
#include <vector>

#include "nanovg.h"

#include "guiobject.hpp"
#include "panel.hpp"

namespace gui {

class Gui {
  public:
    Gui(int windowWidth, int windowHeight);
    ~Gui();

    void render();

    void setWindowParameters(int windowWidth, int windowHeight);

    /**
     * Clear all information currently in the GUI and add pPanel.
     * if pPanel == null, the GUI is cleared
     */
    void setSelectedPanel(std::shared_ptr<Panel> pPanel);

  private:
    NVGcontext* _vg;

    int _windowWidth;
    int _windowHeight;

    std::vector<std::shared_ptr<GuiObject>> _children;
};

} // namespace gui