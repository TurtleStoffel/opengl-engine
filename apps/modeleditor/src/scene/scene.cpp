#include "scene/scene.hpp"

#include "entities/triangle.hpp"

#include "imgui.h"

namespace ModelEditor {
    Scene::Scene(Engine::Shaders::Registry& shaderRegistry)
          : Engine::Scene{shaderRegistry} {
    }

    auto Scene::renderGui() -> void {
        ImGui::Begin("Options");
        if (ImGui::Button("Create Triangle")) {
            createTriangle();
        }
        ImGui::End();
    }

    auto Scene::createTriangle() -> void {
        addEntity(Entities::Triangle::createDefault(m_shaderRegistry));
    }
}