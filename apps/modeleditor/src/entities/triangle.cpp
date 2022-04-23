#include "entities/triangle.hpp"

#include "models/triangle.hpp"

#include "engine/components/models/model_factory.hpp"
#include "engine/components/shader.hpp"
#include "engine/components/transform.hpp"
#include "engine/shaders/lowpoly.hpp"

#include <memory>

namespace ModelEditor::Entities {
    auto Triangle::createDefault(Engine::Shaders::Registry& shaderRegistry)
        -> std::unique_ptr<Engine::Entity> {
        auto entity = std::make_unique<Engine::Entity>(nullptr, "Triangle");

        auto model = Engine::Components::Models::ModelFactory::make<Models::Triangle>(*entity);
        entity->registerComponent<Engine::Components::Model>(std::move(model));

        entity->createAndRegisterComponent<
            Engine::Components::Shader>(*entity,
                                        shaderRegistry.getOrCreate<Engine::Shaders::LowPoly>());

        entity->createAndRegisterComponent<Engine::Components::Transform>(*entity);

        return entity;
    }
}