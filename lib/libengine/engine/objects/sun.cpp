#include "engine/objects/sun.hpp"

#include "engine/color.hpp"
#include "engine/guibinding/gui_factory.hpp"
#include "engine/models/effects/glow.hpp"
#include "engine/models/model_factory.hpp"
#include "engine/models/sphere.hpp"

#include <memory>

Sun::Sun(GuiFactory& guiFactory) : Object{nullptr, "Sun"} {
    _generateModel();

    m_guiBinding = guiFactory.createGui(*this);
}

void Sun::_generateModel() {
    m_model = ModelFactory::make<Sphere>(*this, color::starColor(_temperature));
    m_model->addPreRenderEffect(std::make_unique<Glow>(*m_model.get()));
}