#ifndef PANEL_HPP
#define PANEL_HPP

#include <vector>

#include "gui/guiobject.hpp"

namespace gui {

class Panel : public GuiObject {
    enum StackingMethod { HORIZONTAL, VERTICAL };

   public:
    /**
     * Top Left corner is offset using the defaults from Top Left of parent object. If parent is
     * nullptr, x and y are 0 (top left)
     */
    Panel();
    /**
     * Top Left corner is offset x and y relative to Top Left of parent object. If parent is
     * nullptr, x and y are absolute coordinates
     */
    Panel(int relX, int relY);

    void setMinWidth(int minWidth);
    void setMinHeight(int minHeight);

   protected:
    virtual void _renderImplementation(NVGcontext* vg);

   private:
    int _minWidth;
    int _minHeight;
    StackingMethod _stackingMethod;
};

}  // namespace gui

#endif
