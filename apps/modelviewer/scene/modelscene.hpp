#pragma once

#include "engine/scene/scene.hpp"

#include <limits>

class ShaderRegistry;

namespace Engine {
    class Entity;
}

namespace ModelViewer {
    class ModelScene final : public Engine::Scene {
      public:
        ModelScene(const ShaderRegistry& shaderRegistry);
        ~ModelScene() override = default;

      protected:
        auto renderGui() -> void override;

      private:
        auto createModel(const char* model) -> void;
        auto resetSelectedObject() -> void;

        unsigned short m_selectedModel  = std::numeric_limits<decltype(m_selectedModel)>::max();
        unsigned short m_selectedObject = std::numeric_limits<decltype(m_selectedObject)>::max();

        const std::vector<const char*> m_models = {"Planet##model", "Star##model"};
    };
}