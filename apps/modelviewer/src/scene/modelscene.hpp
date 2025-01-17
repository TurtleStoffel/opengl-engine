#pragma once

#include "engine/scene.hpp"
#include "engine/shaders/registry.hpp"

#include <limits>

namespace Engine {
    class Entity;
}

namespace ModelViewer {
    class ModelScene final : public Engine::Scene {
      public:
        ModelScene(Engine::Shaders::Registry& shaderRegistry);
        ~ModelScene() override = default;

      private:
        auto renderGui() -> void override;

        auto createModel(const char* model) -> void;
        auto resetSelectedObject() -> void;

        unsigned short m_selectedModel  = std::numeric_limits<decltype(m_selectedModel)>::max();
        unsigned short m_selectedObject = std::numeric_limits<decltype(m_selectedObject)>::max();

        const std::vector<const char*> m_models = {"Planet##model", "Star##model"};
    };
}