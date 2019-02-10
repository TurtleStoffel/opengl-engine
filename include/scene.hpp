#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>

#include "opengl.hpp"

#include "camera.hpp"
#include "interfaces/updateable.hpp"
#include "models/model.hpp"
#include "models/selectable.hpp"
#include "objects/object.hpp"

class Scene : public Updateable {
   public:
    virtual ~Scene();

    /**
     * Request current singleton instance
     */
    static Scene* instance();

    void handleInput(SDL_Event event);
    void render();

    void addRenderable(Model* pModel);

    // Updateable Interface
    virtual void update(int t);

   protected:
    /**
     * Protected constructer because Singleton class
     */
    Scene();
    /**
     * Singleton instance
     */
    static Scene* _pScene;

    std::vector<Object*> _objects;
    Camera* _pCamera;

   private:
    virtual void _changeScene() = 0;
    void _mousePick(SDL_Event event);

    std::vector<Selectable*> _selectable;
    std::vector<Model*> _renderable;
};

#endif
