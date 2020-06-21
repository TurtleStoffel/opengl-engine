#include "modelviewerapplication.hpp"

#include "scene/modelscene.hpp"

ModelViewerApplication::ModelViewerApplication(SDL_Window* pWindow) : Application(pWindow) {
}

ModelViewerApplication::~ModelViewerApplication() {
}

void ModelViewerApplication::_createScene() {
    _pScene = std::make_unique<ModelScene>();
    _pScene->initialize();
}