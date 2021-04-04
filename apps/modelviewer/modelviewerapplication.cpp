#include "modelviewerapplication.hpp"

#include "scene/modelscene.hpp"

ModelViewerApplication::ModelViewerApplication(SDL_Window* window)
      : Application{window} {
}

void ModelViewerApplication::_createScene() {
    m_scene = std::make_unique<ModelScene>(m_shaderRegistry);
}