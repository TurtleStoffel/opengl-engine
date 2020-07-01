#pragma once

#include <vector>

#include "guiobject.hpp"

namespace gui {

class Panel : public GuiObject {
    // TODO use this in implementation
    enum StackingMethod { HORIZONTAL, VERTICAL };

  public:
    virtual Bounds loadBounds(NVGcontext* vg);
    void recalculateSize();

  protected:
    virtual void _renderImplementation(NVGcontext* vg);

  private:
    StackingMethod _stackingMethod;
};

} // namespace gui