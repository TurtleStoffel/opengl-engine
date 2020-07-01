#pragma once

#include <string>

#include "guiobject.hpp"

namespace gui {

class TextField : public GuiObject {
  public:
    void setContent(std::string content);

    virtual Bounds loadBounds(NVGcontext* vg);

  protected:
    virtual void _renderImplementation(NVGcontext* vg);

    std::string _content = "";
};

} // namespace gui