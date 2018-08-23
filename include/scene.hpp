#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>

#include "opengl.hpp"

#include "models/model.hpp"
#include "models/selectable.hpp"

class Application;
class Camera;

class Scene {
   public:
    Scene(Application* parent);

    void render();
    void handleInput(SDL_Event event);

   private:
    std::vector<Selectable> _selectable;
    std::vector<Model> _renderable;
    Camera* _camera;
};

#endif
