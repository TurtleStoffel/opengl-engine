#include "guibinding.hpp"

#include "imgui.h"

#include "application.hpp"

GuiBinding::GuiBinding(const Object* pObject) {
    _pObject = pObject;
}

GuiBinding::~GuiBinding() {
    // Empty Virtual Destructor
}

void GuiBinding::changeSelected(bool selected) {
}
