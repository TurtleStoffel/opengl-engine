#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <vector>

#include "scene.hpp"

class Planet;
class Sun;

class System {
   public:
    System(Scene* pScene);
    ~System();

   private:
    std::vector<Planet*> _planets;
    Sun* _pSun;
};

#endif
