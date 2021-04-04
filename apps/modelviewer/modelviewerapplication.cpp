#include "modelviewerapplication.hpp"

#include "scene/modelscene.hpp"

namespace ModelViewer {
    ModelViewerApplication::ModelViewerApplication(SDL_Window* window)
          : Application{window} {
        m_scene = std::make_unique<ModelScene>(m_shaderRegistry);
    }
}