#pragma once

#include "engine/scene/scene.hpp"

#include <limits>

class ModelScene final : public Scene {
  public:
    ModelScene();
    ~ModelScene() override = default;

  protected:
    auto renderGui() -> void override;

  private:
    auto createModel(const char* model) -> void;
    auto resetSelectedObject() -> void;

    unsigned short m_selectedModel  = std::numeric_limits<decltype(m_selectedModel)>::max();
    unsigned short m_selectedObject = std::numeric_limits<decltype(m_selectedObject)>::max();

    Object* m_selectedObjectPointer{nullptr};

    const std::vector<const char*> m_models = {"Planet##model", "Sun##model", "Background##model"};
};