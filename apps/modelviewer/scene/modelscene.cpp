#include "modelscene.hpp"

#include "engine/application.hpp"
#include "engine/objects/planet.hpp"
#include "engine/objects/sun.hpp"
#include "imgui.h"

#include <iostream>

ModelScene::ModelScene() {
    guiFactory = GuiFactory(GuiFactory::GuiType::CONFIGURATION);
}

void ModelScene::_renderGui() {
    ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f));
    ImGui::SetNextWindowSize(ImVec2(150.0f, 200.0f));
    ImGui::Begin("Scene Options");
    for (unsigned int i = 0; i < _models.size(); i++) {
        if (ImGui::Selectable(_models[i], i == _selectedModel)) {
            if (i != _selectedModel) {
                _createModel(_models[i]);
            }
            _selectedModel = i;
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

void ModelScene::_createModel(const char* model) {
    m_objects.clear();

    if (strcmp(model, "Planet") == 0) {
        m_objects.push_back(std::make_unique<Planet>(0.0f, 1.0f));
    } else if (strcmp(model, "Sun") == 0) {
        m_objects.push_back(std::make_unique<Sun>(guiFactory));
    }
}