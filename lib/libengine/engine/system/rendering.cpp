#include "engine/system/rendering.hpp"

#include "engine/components/effect.hpp"
#include "engine/components/gui_component.hpp"
#include "engine/components/model.hpp"

namespace Engine::System {
    Rendering::Rendering(ShaderRegistry& shaderRegistry)
          : m_shaderRegistry{shaderRegistry} {
    }

    auto Rendering::render() const -> void {
        for (const auto& entity : m_entities) {
            if (const auto& effect = entity->get<Components::Effect>()) {
                entity->getRequired<Components::Transform>().passModelMatrixToShader(
                    m_shaderRegistry);
                effect->renderEffects(m_shaderRegistry);
            }
            if (const auto& model = entity->get<Components::Model>()) {
                entity->getRequired<Components::Transform>().passModelMatrixToShader(
                    m_shaderRegistry);
                model->render();
            }
            if (const auto& guiComponent = entity->get<Components::GuiComponent>()) {
                guiComponent->render();
            }
        }
    }

    auto Rendering::registerEntity(Entity* entity) -> void {
        m_entities.insert(entity);
    }

    auto Rendering::unregisterEntity(Entity* entity) -> void {
        m_entities.extract(entity);
    }
}