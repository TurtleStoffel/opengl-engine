#include "guibinding/guibinding.hpp"

#include "application.hpp"

GuiBinding::GuiBinding(Object* pObject) {
    _pObject = pObject;

    _pPanel = new gui::Panel();
}

GuiBinding::~GuiBinding() {
    // Empty virtual destructor
}

void GuiBinding::changeSelected(bool selected) {
    if (selected) {
        Application::instance()->getGui()->setSelectedPanel(_pPanel);
    } else {
        Application::instance()->getGui()->setSelectedPanel(nullptr);
    }
}
