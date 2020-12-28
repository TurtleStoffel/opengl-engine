#include "sun.hpp"

#include <memory>

#include "color.hpp"
#include "guibinding/gui_factory.hpp"
#include "models/effects/glow.hpp"
#include "models/sphere.hpp"

Sun::Sun(GuiFactory guiFactory) {
    _generateModel();

    guiBinding = guiFactory.createSunGui(this);
}

void Sun::_generateModel() {
    model = std::make_unique<Sphere>(*transform.get(), color::starColor(_temperature));
    model->addEffect(std::make_unique<Glow>(*model.get()));
}