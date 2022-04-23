#include "engine/systems/rendering.hpp"

#include "engine/components/effects/effect_container.hpp"
#include "engine/components/gui_component.hpp"
#include "engine/components/model.hpp"

namespace Engine::Systems {
    Rendering::Rendering(Shaders::Registry& shaderRegistry)
          : m_shaderRegistry{shaderRegistry} {
    }

    auto Rendering::render() const -> void {
        for (const auto& entity : m_entities) {
            if (const auto& effect = entity->get<Components::EffectContainer>()) {
                entity->getRequired<Components::Transform>().passModelMatrixToShader(
                    m_shaderRegistry);
                effect->renderEffects();
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