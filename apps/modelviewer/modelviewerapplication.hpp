#pragma once

#include "engine/application.hpp"

namespace ModelViewer {
    class ModelViewerApplication : public Application {
      public:
        ModelViewerApplication(SDL_Window* pWindow);
        ~ModelViewerApplication() override = default;
    };
}