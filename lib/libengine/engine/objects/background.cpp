#include "engine/objects/background.hpp"

#include "engine/components/models/background_model.hpp"
#include "engine/components/models/model_factory.hpp"
#include "engine/components/shader_component.hpp"
#include "engine/components/shaders/generic_shader_component.hpp"
#include "engine/shaders/backgroundshader.hpp"
#include "engine/shaders/shaderregistry.hpp"

auto Background::createDefault(const ShaderRegistry& shaderRegistry)
    -> std::unique_ptr<Background> {
    auto background = std::make_unique<Background>();

    background->registerComponent<Engine::Components::ShaderComponent>(
        std::make_unique<Engine::Components::Shaders::GenericShaderComponent>(
            *background, shaderRegistry.get<BackgroundShader>()));

    background->registerComponent<Engine::Components::Transform>(
        std::make_unique<Engine::Components::Transform>(*background));

    background->registerComponent<Engine::Components::Model>(
        Engine::Components::Models::ModelFactory::make<Engine::Components::Models::BackgroundModel>(
            *background));

    return background;
}

Background::Background()
      : Engine::Entity{nullptr, "Background"} {
}