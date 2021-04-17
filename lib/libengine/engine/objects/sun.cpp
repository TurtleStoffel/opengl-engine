#include "engine/objects/sun.hpp"

#include "engine/color.hpp"
#include "engine/components/shader_component.hpp"
#include "engine/components/shaders/generic_shader_component.hpp"
#include "engine/guibinding/gui_factory.hpp"
#include "engine/models/effects/glow.hpp"
#include "engine/models/model_factory.hpp"
#include "engine/models/sphere.hpp"
#include "engine/shaders/lowpolyshader.hpp"
#include "engine/shaders/shaderregistry.hpp"

#include <memory>
#include <utility>

auto Sun::createDefault(GuiFactory& guiFactory, const ShaderRegistry& shaderRegistry)
    -> std::unique_ptr<Sun> {
    auto sun = std::make_unique<Sun>(guiFactory);

    sun->registerComponent<Engine::Components::ShaderComponent>(
        std::make_unique<Engine::Components::Shaders::GenericShaderComponent>(
            *sun, shaderRegistry.get<LowPolyShader>()));
    sun->registerComponent<Engine::Components::Transform>(
        std::make_unique<Engine::Components::Transform>(*sun));

    return sun;
}

Sun::Sun(GuiFactory& guiFactory)
      : Entity{nullptr, "Sun"} {
    _generateModel();

    m_guiBinding = guiFactory.createGui(*this);
}

void Sun::_generateModel() {
    auto colorGenerator = [this]([[maybe_unused]] float height) {
        return color::starColor(m_temperature);
    };
    m_model = ModelFactory::make<Engine::Sphere>(*this, colorGenerator);
    m_model->addPreRenderEffect(std::make_unique<Glow>(*m_model.get()));
}