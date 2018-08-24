#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>

#include "opengl.hpp"

#include "interfaces/updateable.hpp"

#include "models/model.hpp"
#include "models/selectable.hpp"

#include "objects/object.hpp"

class Application;
class Camera;

class Scene : public Updateable {
   public:
    Scene(Application* pParent);
    virtual ~Scene();

    void handleInput(SDL_Event event);
    void render();

    void addRenderable(Model* pModel);

    // Updateable Interface
    virtual void update(int t);

   private:
    std::vector<Selectable*> _selectable;
    std::vector<Model*> _renderable;
    std::vector<Object*> _objects;
    Camera* _camera;
};

#endif
