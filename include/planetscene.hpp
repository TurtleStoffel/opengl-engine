#ifndef PLANETSCENE_HPP
#define PLANETSCENE_HPP

#include "scene.hpp"

class PlanetScene : public Scene {
    friend class SystemScene;

   public:
    static Scene* setInitialScene();

   private:
    PlanetScene();

    void _changeScene();
};

#endif
