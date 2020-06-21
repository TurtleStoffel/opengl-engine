#pragma once

#include <string>

#include "opengl.hpp"

class SDL {
  public:
    static SDL_Window* createWindow(const std::string name);
    static void destroy(SDL_Window* pWindow);
};