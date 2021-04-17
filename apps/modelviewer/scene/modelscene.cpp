#include "modelscene.hpp"

#include "engine/components/gui/component_gui.hpp"
#include "engine/components/gui_component.hpp"
#include "engine/components/script.hpp"
#include "engine/components/scripts/demo_rotation.hpp"
#include "engine/objects/background.hpp"
#include "engine/objects/entity.hpp"
#include "engine/objects/planet.hpp"
#include "engine/objects/sun.hpp"

#include "imgui.h"

namespace ModelViewer {
    ModelScene::ModelScene(const ShaderRegistry& shaderRegistry)
          : Scene{shaderRegistry} {
        m_guiFactory = GuiFactory{GuiFactory::GuiType::CONFIGURATION};
        m_objects.push_back(Background::createDefault(m_shaderRegistry));
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
        for (auto& object : m_objects) {
            object->visit([this, &i](Engine::Entity& element) {
                ImGui::Indent(element.getDepth() * 8.0f);
                if (ImGui::Selectable(element.getName().c_str(), i == m_selectedObject)) {
                    if (i != m_selectedObject) {
                        m_selectedObjectPointer = &element;
                    }
                    m_selectedObject = i;
                }
                ImGui::Unindent(element.getDepth() * 8.0f);

                // Increment in lambda to increment per object (outside of lambda is per root
                // object)
                i++;
            });
        }

        if (m_selectedObjectPointer) {
            auto transform = m_selectedObjectPointer->get<Engine::Components::Transform>();
            assert(transform);

            ImGui::Separator();
            ImGui::Text("Details of selected Model");
            ImGui::Text("Relative Position");
            ImGui::DragFloat3("##positionDrags", &transform->m_position[0], 0.05f);
            ImGui::Text("Rotation");
            ImGui::DragFloat3("##rotationDrags", &transform->m_rotationYXZ[0], 0.05f);
            ImGui::Text("Scale");
            ImGui::DragFloat3("##scaleDrags", &transform->m_scale[0], 0.05f);
        }

        ImGui::End();
    }

    auto ModelScene::createModel(const char* model) -> void {
        m_objects.clear();
        m_objects.push_back(Background::createDefault(m_shaderRegistry));

        auto object = std::unique_ptr<Engine::Entity>{nullptr};

        if (strcmp(model, "Planet##model") == 0) {
            object = Planet::createDefault(0.0f, 3.0f, m_shaderRegistry);
            object->registerComponent<Engine::Components::GuiComponent>(
                std::make_unique<Engine::Components::Gui::ComponentGui>(*object));
            object->registerComponent<Engine::Components::Script>(
                std::make_unique<Engine::Components::Scripts::DemoRotation>(*object));
        } else if (strcmp(model, "Sun##model") == 0) {
            object = Sun::createDefault(m_guiFactory, m_shaderRegistry);
        }

        if (object) {
            m_selectedObjectPointer = object.get();
            m_objects.push_back(std::move(object));
        }
    }

    auto ModelScene::resetSelectedObject() -> void {
        m_selectedObject        = std::numeric_limits<decltype(m_selectedObject)>::max();
        m_selectedObjectPointer = nullptr;
    }
}