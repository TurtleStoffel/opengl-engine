#include "modelscene.hpp"

#include "engine/application.hpp"
#include "engine/objects/planet.hpp"
#include "engine/objects/sun.hpp"
#include "imgui.h"

#include <iostream>

ModelScene::ModelScene() {
    m_guiFactory = GuiFactory{GuiFactory::GuiType::CONFIGURATION};
}

auto ModelScene::renderGui() -> void {
    ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f));
    ImGui::SetNextWindowSize(ImVec2(150.0f, 200.0f));
    ImGui::Begin("Scene Options");
    for (unsigned int i = 0; i < m_models.size(); i++) {
        if (ImGui::Selectable(m_models[i], i == m_selectedModel)) {
            if (i != m_selectedModel) {
                createModel(m_models[i]);
            }
            m_selectedModel = i;
        }
    }

    ImGui::Separator();
    ImGui::Text("Models in scene");

    for (auto& object : m_objects) {
        object->visit([](const Object& element) {
            ImGui::Indent(element.getDepth() * 8.0f);
            ImGui::Text("%s", element.getName().c_str());
            ImGui::Unindent(element.getDepth() * 8.0f);
        });
    }
    ImGui::End();
}

auto ModelScene::createModel(const char* model) -> void {
    m_objects.clear();

    if (strcmp(model, "Planet") == 0) {
        m_objects.push_back(std::make_unique<Planet>(0.0f, 1.0f));
    } else if (strcmp(model, "Sun") == 0) {
        m_objects.push_back(std::make_unique<Sun>(m_guiFactory));
    }
}