#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>

#include "opengl.hpp"
#include "updateable.hpp"

#include "models/model.hpp"
#include "models/selectable.hpp"

class Application;
class Camera;

class Scene : public Updateable {
   public:
    Scene(Application* pParent);
    virtual ~Scene();

    void handleInput(SDL_Event event);
    void render();

    // Updateable Interface
    virtual void update(int t);

   private:
    std::vector<Selectable> _selectable;
    std::vector<Model> _renderable;
    Camera* _camera;
};

#endif
