#include "engine/objects/background.hpp"

#include "engine/components/models/background_model.hpp"
#include "engine/components/models/model_factory.hpp"
#include "engine/components/shader_component.hpp"
#include "engine/components/shaders/generic_shader_component.hpp"
#include "engine/shaders/backgroundshader.hpp"
#include "engine/shaders/shaderregistry.hpp"

namespace Engine {
    auto Background::createDefault(const ShaderRegistry& shaderRegistry)
        -> std::unique_ptr<Background> {
        auto background = std::make_unique<Background>();

        background->registerComponent<Components::ShaderComponent>(
            std::make_unique<Components::Shaders::GenericShaderComponent>(*background,
                                                                          shaderRegistry.get<
                                                                              BackgroundShader>()));

        background->createAndRegisterComponent<Components::Transform>(*background);

        background->registerComponent<Components::Model>(
            Components::Models::ModelFactory::make<Components::Models::BackgroundModel>(
                *background));

        return background;
    }

    Background::Background()
          : Entity{nullptr, "Background"} {
    }
}