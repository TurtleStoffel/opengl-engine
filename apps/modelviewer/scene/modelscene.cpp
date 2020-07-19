#include "modelscene.hpp"

#include "imgui.h"

#include "application.hpp"
#include "objects/planet.hpp"
#include "objects/sun.hpp"

void ModelScene::initialize() {
    camera->setOrientation(glm::vec3(0.0f, 0.0f, 5.0f),
                           glm::vec3(0.0f, 0.0f, 0.0f),
                           glm::vec3(0.0f, 1.0f, 0.0f));
    camera->setFlatMovement();

    guiFactory = GuiFactory(GuiFactory::CONFIGURATION);
}

void ModelScene::_renderGui() {
    ImGui::Begin("Model Selector");
    for (unsigned int i = 0; i < _models.size(); i++) {
        if (ImGui::Selectable(_models[i], i == _selectedModel)) {
            if (i != _selectedModel) {
                _createModel(_models[i]);
            }
            _selectedModel = i;
        }
    }
    ImGui::End();
}

void ModelScene::_createModel(const char* model) {
    _objects.clear();

    if (strcmp(model, "Planet") == 0) {
        _objects.push_back(std::make_unique<Planet>(0.0f, 1.0f));
    } else if (strcmp(model, "Sun") == 0) {
        _objects.push_back(std::make_unique<Sun>(guiFactory));
    }
}