#pragma once

#include "engine/scene/scene.hpp"

class ModelScene final : public Scene {
  public:
    ModelScene();
    ~ModelScene() override = default;

  protected:
    auto renderGui() -> void override;

  private:
    auto createModel(const char* model) -> void;

    unsigned int m_selectedModel            = -1;
    const std::vector<const char*> m_models = {"Planet", "Sun"};
};