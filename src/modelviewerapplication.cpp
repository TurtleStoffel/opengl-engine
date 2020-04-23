#include "modelviewerapplication.hpp"

#include "scene/planetscene.hpp"

ModelViewerApplication::ModelViewerApplication(SDL_Window* pWindow) : Application(pWindow) {
}

ModelViewerApplication::~ModelViewerApplication() {
}

void ModelViewerApplication::_createScene() {
    _pScene = std::make_unique<PlanetScene>();
    _pScene->initialize();
}