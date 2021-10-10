#include "engine/objects/background.hpp"

#include "engine/components/models/background_model.hpp"
#include "engine/components/models/model_factory.hpp"
#include "engine/components/shader_component.hpp"
#include "engine/components/shaders/generic_shader_component.hpp"
#include "engine/objects/entity.hpp"
#include "engine/shaders/backgroundshader.hpp"
#include "engine/shaders/shaderregistry.hpp"

namespace Engine {
    auto Background::createDefault(ShaderRegistry& shaderRegistry) -> std::unique_ptr<Entity> {
        auto entity = std::make_unique<Entity>(nullptr, "Background");

        entity->registerComponent<Components::ShaderComponent>(
            std::make_unique<Components::Shaders::GenericShaderComponent>(
                *entity, shaderRegistry.getOrCreate<BackgroundShader>()));

        entity->createAndRegisterComponent<Components::Transform>(*entity);

        entity->registerComponent<Components::Model>(
            Components::Models::ModelFactory::make<Components::Models::BackgroundModel>(*entity));

        return entity;
    }
}