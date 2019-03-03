#ifndef PANEL_HPP
#define PANEL_HPP

#include <vector>

#include "gui/guiobject.hpp"

namespace gui {

class Panel : public GuiObject {
   public:
    /**
     * Construct Panel with x and y the coordinates of the Top Left Corner
     */
    Panel(int relX, int relY);

    void setMinWidth(int minWidth);
    void setMinHeight(int minHeight);

   protected:
    virtual void _renderImplementation(NVGcontext* vg);

   private:
    int _minWidth;
    int _minHeight;
};

}  // namespace gui

#endif
