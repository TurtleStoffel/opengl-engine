#include "engine/objects/sun.hpp"

#include "engine/color.hpp"
#include "engine/components/collider.hpp"
#include "engine/components/models/model_factory.hpp"
#include "engine/components/models/sphere.hpp"
#include "engine/components/shader_component.hpp"
#include "engine/components/shaders/generic_shader_component.hpp"
#include "engine/models/effects/glow.hpp"
#include "engine/shaders/lowpolyshader.hpp"
#include "engine/shaders/shaderregistry.hpp"

#include <memory>
#include <utility>

auto Sun::createDefault(const ShaderRegistry& shaderRegistry) -> std::unique_ptr<Sun> {
    auto sun = std::make_unique<Sun>();

    sun->registerComponent<Engine::Components::ShaderComponent>(
        std::make_unique<Engine::Components::Shaders::GenericShaderComponent>(
            *sun, shaderRegistry.get<LowPolyShader>()));
    sun->registerComponent<Engine::Components::Transform>(
        std::make_unique<Engine::Components::Transform>(*sun));
    sun->registerComponent<Engine::Components::Collider>(
        std::make_unique<Engine::Components::Collider>(*sun));

    return sun;
}

Sun::Sun()
      : Entity{nullptr, "Sun"} {
    auto colorGenerator = [this]([[maybe_unused]] float height) {
        return color::starColor(m_temperature);
    };
    auto model = Engine::Components::Models::ModelFactory::make<
        Engine::Components::Models::Sphere>(*this, colorGenerator);
    model->addPreRenderEffect(std::make_unique<Glow>(*model.get()));

    registerComponent<Engine::Components::Model>(std::move(model));
}

auto Sun::generateModel() -> void {
}