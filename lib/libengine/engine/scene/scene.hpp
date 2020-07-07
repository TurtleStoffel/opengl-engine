#pragma once

#include <vector>

#include "opengl.hpp"

#include "camera.hpp"
#include "interfaces/updateable.hpp"
#include "models/model.hpp"
#include "objects/object.hpp"

class Scene : public Updateable {
  public:
    virtual ~Scene() {};

    bool handleInput(SDL_Event event);
    void render();

    // Updateable Interface
    virtual void update(int t);

    virtual void initialize() = 0;

  protected:
    std::vector<std::unique_ptr<Object>> _objects;

  private:
    void _mousePick(SDL_Event event);
};