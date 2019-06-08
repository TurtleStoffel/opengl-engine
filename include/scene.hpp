#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>

#include "opengl.hpp"

#include "camera.hpp"
#include "interfaces/updateable.hpp"
#include "models/model.hpp"
#include "objects/object.hpp"

class Scene : public Updateable {
   public:
    virtual ~Scene();

    /**
     * Request current singleton instance
     */
    static Scene* instance();

    bool handleInput(SDL_Event event);
    void render();

    void addRenderable(Model* pModel);
    void addCollider(Collider* pCollider);

    // Updateable Interface
    virtual void update(int t);

   protected:
    /**
     * Protected constructer because Singleton class
     */
    Scene();

    virtual void _initialize() = 0;

    /**
     * Singleton instance
     */
    static Scene* _pScene;

    std::vector<Object*> _objects;
    Camera* _pCamera;

   private:
    virtual void _changeScene() = 0;
    void _mousePick(SDL_Event event);

    std::vector<Model*> _models;
    std::vector<Collider*> _colliders;
};

#endif
