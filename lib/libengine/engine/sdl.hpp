#pragma once

#include <string>

#include "opengl.hpp"

class SDL {
  public:
    static auto createWindow(const std::string name) -> SDL_Window*;
    static auto destroy(SDL_Window* pWindow) -> void;
};