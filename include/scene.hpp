#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>

#include "opengl.hpp"

#include "models/model.hpp"
#include "models/selectable.hpp"

class Scene {
   public:
    Scene();
    ~Scene();

    void render();
    void handleInput(SDL_Event event);

   private:
    std::vector<Selectable> _selectable;
    std::vector<Model> _renderable;
    // Model* _pModel;
};

#endif
