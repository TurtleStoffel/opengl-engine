#include "engine/sdl.hpp"
#include "modelviewerapplication.hpp"

#include <memory>
#include <time.h>

int main() {
    SDL_Window* window = SDL::createWindow("ModelViewer");

    // set random seed
    srand(time(NULL));

    std::unique_ptr<Application> application = std::make_unique<ModelViewerApplication>(window);
    application->run();

    SDL::destroy(window);

    return 0;
}