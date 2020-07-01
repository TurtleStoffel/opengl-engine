#pragma once

#include <string>

#include "guiobject.hpp"

namespace gui {

class ListView : public GuiObject {
  public:
    void setContent(std::vector<std::string> content);

    virtual Bounds loadBounds(NVGcontext* vg);

  protected:
    virtual void _renderImplementation(NVGcontext* vg);

  private:
    std::vector<std::string> _content;
};

} // namespace gui