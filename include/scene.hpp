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
    Scene();
    virtual ~Scene();

    bool handleInput(SDL_Event event);
    void render();

    void addRenderable(Model* pModel);
    void addCollider(Collider* pCollider);

    /**
     * Get raw pointer to Camera Instance. DO NOT CALL DELETE or keep a reference to this Pointer!
     */
    Camera* getCamera();

    // Updateable Interface
    virtual void update(int t);

    virtual void initialize() = 0;

   protected:
    std::vector<Object*> _objects;
    std::unique_ptr<Camera> _pCamera;

   private:
    void _mousePick(SDL_Event event);

    std::vector<Model*> _models;
    std::vector<Collider*> _colliders;
};

#endif
