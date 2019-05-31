#ifndef SUNGUI_HPP
#define SUNGUI_HPP

#include "gui/panel.hpp"
#include "gui/textfield.hpp"
#include "guibinding/guibinding.hpp"

class SunGuiBinding : public GuiBinding {
   public:
    SunGuiBinding(Object* pObject);
    ~SunGuiBinding(){};

    virtual void render();

   private:
    gui::TextField* _pTemperatureText;
};

#endif
