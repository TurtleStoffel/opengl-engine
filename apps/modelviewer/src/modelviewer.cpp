#include "engine/sdl.hpp"
#include "modelviewerapplication.hpp"

#include <memory>
#include <time.h>

int main() {
    auto window = Engine::SDL::createWindow("ModelViewer");

    // set random seed
    srand(time(NULL));

    auto application = std::make_unique<ModelViewer::ModelViewerApplication>(*window);
    application->run();

    Engine::SDL::destroy(window);

    return 0;
}