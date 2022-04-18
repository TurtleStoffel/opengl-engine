#pragma once

#include "engine/application.hpp"

namespace ModelViewer {
    class ModelViewerApplication : public Engine::Application {
      public:
        ModelViewerApplication(SDL_Window& window);
        ~ModelViewerApplication() override = default;
    };
}