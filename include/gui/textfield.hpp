#ifndef TEXTFIELD_HPP
#define TEXTFIELD_HPP

#include <string>

#include "gui/guiobject.hpp"

namespace gui {

class TextField : public GuiObject {
   public:
    TextField(GuiObject* pParent);
    TextField(GuiObject* pParent, int relX, int relY);

    void setContent(std::string content);

    virtual void getBounds(NVGcontext* vg, float* bounds);

   protected:
    virtual void _renderImplementation(NVGcontext* vg);

    std::string _content = "";
};

}  // namespace gui

#endif
