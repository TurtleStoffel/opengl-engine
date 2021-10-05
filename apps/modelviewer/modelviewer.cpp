#include "engine/sdl.hpp"
#include "modelviewerapplication.hpp"

#include <memory>
#include <time.h>

int main() {
    auto window = SDL::createWindow("ModelViewer");

    // set random seed
    srand(time(NULL));

    auto application = std::make_unique<ModelViewer::ModelViewerApplication>(window);
    application->run();

    SDL::destroy(window);

    return 0;
}