#include "gameapplication.hpp"

#include "systemscene.hpp"

GameApplication::GameApplication(SDL_Window* pWindow) : Application(pWindow) {
}

GameApplication::~GameApplication() {
}

void GameApplication::_createScene() {
    // System Scene
    _pScene = std::make_unique<SystemScene>();
    _pScene->initialize();
    // Planet Scene
    /*
    _pScene = std::make_unique<PlanetScene>();
    _pScene->initialize();
    */
}