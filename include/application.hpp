#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "opengl.hpp"

class Application {
   public:
    Application();
    ~Application();
    void run();

   private:
    bool _stop = false;
    int _windowWidth = 800;
    int _windowHeight = 600;
    const int FPS = 30;

    SDL_Window* _pWindow;
    GLuint _shader;
};

#endif
