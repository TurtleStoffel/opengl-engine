#pragma once

#include "scene/scene.hpp"

class ModelScene : public Scene {
  public:
    void initialize();

  protected:
    virtual void _renderGui();

  private:
    void _createModel(const char* model);

    unsigned int _selectedModel            = -1;
    const std::vector<const char*> _models = {"Planet", "Sun"};
};