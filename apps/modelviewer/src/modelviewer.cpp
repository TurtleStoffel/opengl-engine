#include "engine/sdl.hpp"
#include "modelviewerapplication.hpp"

int main() {
    Engine::SDL::startApplication<ModelViewer::ModelViewerApplication>("ModelViewer");
    return 0;
}