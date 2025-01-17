#include "engine/entities/background.hpp"

#include "engine/components/models/background_model.hpp"
#include "engine/components/models/model_factory.hpp"
#include "engine/components/shader.hpp"
#include "engine/entities/entity.hpp"
#include "engine/shaders/background.hpp"

namespace Engine {
    auto Background::createDefault(Shaders::Registry& shaderRegistry) -> std::unique_ptr<Entity> {
        auto entity = std::make_unique<Entity>(nullptr, "Background");

        entity->createAndRegisterComponent<
            Components::Shader>(*entity, shaderRegistry.getOrCreate<Shaders::Background>());

        entity->createAndRegisterComponent<Components::Transform>(*entity);

        entity->registerComponent<Components::Model>(
            Components::Models::ModelFactory::make<Components::Models::BackgroundModel>(*entity));

        return entity;
    }
}