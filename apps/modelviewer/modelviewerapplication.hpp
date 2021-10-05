#pragma once

#include "engine/application.hpp"

namespace ModelViewer {
    class ModelViewerApplication : public Engine::Application {
      public:
        ModelViewerApplication(SDL_Window* pWindow);
        ~ModelViewerApplication() override = default;
    };
}