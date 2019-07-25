#ifndef PANEL_HPP
#define PANEL_HPP

#include <vector>

#include "gui/guiobject.hpp"

namespace gui {

class Panel : public GuiObject {
    // TODO use this in implementation
    enum StackingMethod { HORIZONTAL, VERTICAL };

   public:
    /**
     * Top Left corner is offset using the defaults from Top Left of parent object. If parent is
     * nullptr, x and y are 0 (top left)
     */
    Panel(GuiObject* pParent);
    /**
     * Top Left corner is offset x and y relative to Top Left of parent object. If parent is
     * nullptr, x and y are absolute coordinates
     */
    Panel(GuiObject* pParent, int relX, int relY);

    void setWidth(int width);
    void setHeight(int height);

    virtual void calculateBounds(NVGcontext* vg);
    virtual void getBounds(NVGcontext* vg, float* bounds);
    void recalculateSize();

   protected:
    virtual void _renderImplementation(NVGcontext* vg);

   private:
    int _width;
    int _height;
    StackingMethod _stackingMethod;
};

}  // namespace gui

#endif
