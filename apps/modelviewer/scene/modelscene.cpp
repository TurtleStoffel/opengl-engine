#include "modelscene.hpp"

#include "engine/components/effect.hpp"
#include "engine/components/effects/debug_vectors.hpp"
#include "engine/components/gui/component_gui.hpp"
#include "engine/components/gui/star_configuration_gui.hpp"
#include "engine/components/gui_component.hpp"
#include "engine/components/script.hpp"
#include "engine/components/scripts/demo_rotation.hpp"
#include "engine/objects/background.hpp"
#include "engine/objects/entity.hpp"
#include "engine/objects/planet.hpp"
#include "engine/objects/star.hpp"

#include "imgui.h"

#include <limits>

namespace ModelViewer {
    ModelScene::ModelScene(const ShaderRegistry& shaderRegistry)
          : Scene{shaderRegistry} {
        m_entities.push_back(Engine::Background::createDefault(m_shaderRegistry));
    }

    auto ModelScene::renderGui() -> void {
        ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f));
        ImGui::SetNextWindowSize(ImVec2(250.0f, 400.0f));
        ImGui::Begin("Scene Options");
        for (unsigned int i = 0; i < m_models.size(); i++) {
            if (ImGui::Selectable(m_models[i], i == m_selectedModel)) {
                if (i != m_selectedModel) {
                    resetSelectedObject();
                    createModel(m_models[i]);
                }
                m_selectedModel = i;
            }
        }

        ImGui::Separator();
        ImGui::Text("Models in scene");

        unsigned short i = 0;
        for (auto& entity : m_entities) {
            entity->visit([this, &i](Engine::Entity& element) {
                ImGui::Indent(element.getDepth() * 8.0f);
                if (ImGui::Selectable(element.getName().c_str(), i == m_selectedObject)) {
                    m_selectedObject = i;
                }
                ImGui::Unindent(element.getDepth() * 8.0f);

                // Increment in lambda to increment per object (outside of lambda is per root
                // object)
                i++;
            });
        }

        ImGui::End();
    }

    auto ModelScene::createModel(const char* model) -> void {
        m_entities.clear();
        m_entities.push_back(Engine::Background::createDefault(m_shaderRegistry));

        auto object = std::unique_ptr<Engine::Entity>{nullptr};

        using namespace Engine::Components;

        if (strcmp(model, "Planet##model") == 0) {
            object = Engine::Planet::createDefault(0.0f, 3.0f, m_shaderRegistry);

            auto& guiComponent = object->getRequired<GuiComponent>();
            guiComponent.addSubcomponent(std::make_unique<Gui::ComponentGui>(*object));

            object->registerComponent<Script>(std::make_unique<Scripts::DemoRotation>(*object));
        } else if (strcmp(model, "Star##model") == 0) {
            object = Engine::Star::createDefault(m_shaderRegistry);

            auto& guiComponent = object->getRequired<GuiComponent>();
            guiComponent.addSubcomponent(std::make_unique<Gui::ComponentGui>(*object));
            guiComponent.addSubcomponent(std::make_unique<Gui::StarConfigurationGui>(*object));
        }

        if (object) {
            auto& effectComponent = object->getRequired<Effect>();
            effectComponent.addEffect(std::make_unique<Effects::DebugVectors>(*object));

            m_entities.push_back(std::move(object));
        }
    }

    auto ModelScene::resetSelectedObject() -> void {
        m_selectedObject = std::numeric_limits<decltype(m_selectedObject)>::max();
    }
}