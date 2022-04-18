#pragma once

#include "engine/opengl.hpp"

#include <string>

namespace Engine {
    class SDL {
      public:
        static auto createWindow(const std::string name) -> SDL_Window*;
        static auto destroy(SDL_Window* pWindow) -> void;
    };
}