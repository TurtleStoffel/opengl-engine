#include "engine/objects/sun.hpp"

#include "engine/color.hpp"
#include "engine/guibinding/gui_factory.hpp"
#include "engine/models/effects/glow.hpp"
#include "engine/models/model_factory.hpp"
#include "engine/models/sphere.hpp"

#include <memory>

Sun::Sun(GuiFactory& guiFactory) : Object{nullptr, "Sun"} {
    _generateModel();

    guiBinding = guiFactory.createGui(this);
}

void Sun::_generateModel() {
    model = ModelFactory::make<Sphere>(*transform.get(), color::starColor(_temperature));
    model->addPreRenderEffect(std::make_unique<Glow>(*model.get()));
}