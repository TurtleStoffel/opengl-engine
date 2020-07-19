#include "sun.hpp"

#include <memory>

#include "color.hpp"
#include "guibinding/gui_factory.hpp"
#include "models/sphere.hpp"

Sun::Sun(GuiFactory guiFactory) {
    _generateModel();

    _pGuiBinding = guiFactory.createSunGui(this);
}

void Sun::_generateModel() {
    _pModel = std::make_unique<Sphere>(_pTransform.get(), color::starColor(_temperature));
}