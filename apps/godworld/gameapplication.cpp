#include "gameapplication.hpp"

#include "scene/systemscene.hpp"

GameApplication::GameApplication(SDL_Window* pWindow) : Application(pWindow) {
}

GameApplication::~GameApplication() {
}

void GameApplication::_createScene() {
    scene = std::make_unique<SystemScene>();
}