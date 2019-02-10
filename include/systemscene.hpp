#ifndef SYSTEMSCENE_HPP
#define SYSTEMSCENE_HPP

#include "scene.hpp"

class SystemScene : public Scene {
    friend class PlanetScene;

   public:
    static Scene* setInitialScene();

   protected:
    SystemScene();

    virtual void _changeScene();
};

#endif
