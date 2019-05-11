#ifndef SUNGUI_HPP
#define SUNGUI_HPP

#include "gui/panel.hpp"
#include "gui/textfield.hpp"

// Forward declaration of Sun because of circular dependencies
class Sun;

class SunGuiBinding {
   public:
    SunGuiBinding(Sun* pSun);

   private:
    void _update();

    Sun* _pSun;
    gui::Panel* _pPanel;
    gui::TextField* _pTemperatureText;
};

#endif
