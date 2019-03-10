#ifndef TEXTFIELD_HPP
#define TEXTFIELD_HPP

#include <string>

#include "gui/guiobject.hpp"

namespace gui {

class TextField : public GuiObject {
   public:
    TextField();
    TextField(int relX, int relY);

    void setContent(std::string content);

    /**
     * parameter bounds should be a pointer to float[4]. Return with format [xmin, ymin, xmax, ymax]
     */
    void getBounds(NVGcontext* vg, float* bounds);

   protected:
    virtual void _renderImplementation(NVGcontext* vg);

   private:
    std::string _content;
};

}  // namespace gui

#endif
