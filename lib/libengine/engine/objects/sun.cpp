#include "engine/objects/sun.hpp"

#include "engine/color.hpp"
#include "engine/guibinding/gui_factory.hpp"
#include "engine/models/effects/glow.hpp"
#include "engine/models/sphere.hpp"

#include <memory>

Sun::Sun(GuiFactory guiFactory) : Object{nullptr, "Sun"} {
    _generateModel();

    guiBinding = guiFactory.createSunGui(this);
}

void Sun::_generateModel() {
    model = std::make_unique<Sphere>(*transform.get(), color::starColor(_temperature));
    model->addEffect(std::make_unique<Glow>(*model.get()));
}