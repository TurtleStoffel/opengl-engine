#include "modelscene.hpp"

#include "engine/objects/background.hpp"
#include "engine/objects/planet.hpp"
#include "engine/objects/sun.hpp"

#include "imgui.h"

ModelScene::ModelScene(const ShaderRegistry& shaderRegistry)
      : Scene{shaderRegistry} {
    m_guiFactory = GuiFactory{GuiFactory::GuiType::CONFIGURATION};
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
        object->visit([this, &i](Object& element) {
            ImGui::Indent(element.getDepth() * 8.0f);
            if (ImGui::Selectable(element.getName().c_str(), i == m_selectedObject)) {
                if (i != m_selectedObject) {
                    m_selectedObjectPointer = &element;
                }
                m_selectedObject = i;
            }
            ImGui::Unindent(element.getDepth() * 8.0f);

            // Increment in lambda to increment per object (outside of lambda is per root object)
            i++;
        });
    }

    if (m_selectedObjectPointer) {
        ImGui::Separator();
        ImGui::Text("Details of selected Model");
        auto& relativePosition = m_selectedObjectPointer->getTransform().m_position;
        ImGui::Text("Relative Position");
        ImGui::DragFloat3("##positionDrags", &relativePosition[0], 0.05f);
        auto& rotation = m_selectedObjectPointer->getTransform().m_rotation;
        ImGui::Text("Rotation");
        ImGui::DragFloat("##rotationDrag", &rotation, 0.05f);
        auto& scale = m_selectedObjectPointer->getTransform().m_scale;
        ImGui::Text("Scale");
        ImGui::DragFloat3("##scaleDrags", &scale[0], 0.05f);
    }

    ImGui::End();
}

auto ModelScene::createModel(const char* model) -> void {
    m_objects.clear();

    if (strcmp(model, "Planet##model") == 0) {
        m_objects.push_back(Planet::createDefault(0.0f, 1.0f, m_shaderRegistry));
    } else if (strcmp(model, "Sun##model") == 0) {
        m_objects.push_back(Sun::createDefault(m_guiFactory, m_shaderRegistry));
    } else if (strcmp(model, "Background##model") == 0) {
        m_objects.push_back(Background::createDefault(m_shaderRegistry));
    }
}

auto ModelScene::resetSelectedObject() -> void {
    m_selectedObject        = std::numeric_limits<decltype(m_selectedObject)>::max();
    m_selectedObjectPointer = nullptr;
}