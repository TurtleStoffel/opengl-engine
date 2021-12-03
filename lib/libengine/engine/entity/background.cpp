#include "engine/entity/background.hpp"

#include "engine/components/models/background_model.hpp"
#include "engine/components/models/model_factory.hpp"
#include "engine/components/shader.hpp"
#include "engine/entity/entity.hpp"
#include "engine/shaders/backgroundshader.hpp"

namespace Engine {
    auto Background::createDefault(ShaderRegistry& shaderRegistry,
                                   System::Rendering& renderingSystem) -> std::unique_ptr<Entity> {
        auto entity = std::make_unique<Entity>(nullptr, "Background");

        renderingSystem.registerEntity(entity.get());

        entity->createAndRegisterComponent<
            Components::Shader>(*entity, shaderRegistry.getOrCreate<BackgroundShader>());

        entity->createAndRegisterComponent<Components::Transform>(*entity);

        entity->registerComponent<Components::Model>(
            Components::Models::ModelFactory::make<Components::Models::BackgroundModel>(*entity));

        return entity;
    }
}