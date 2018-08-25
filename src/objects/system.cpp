#include "objects/system.hpp"

#include "objects/planet.hpp"
#include "objects/sun.hpp"

System::System(Scene* pScene) {
    _pSun = new Sun(pScene);
    for (int i = 0; i < 3; i++) {
        _planets.push_back(new Planet(pScene));
    }
}

System::~System() {
    delete _pSun;
    for (Planet* pPlanet : _planets) {
        delete pPlanet;
    }
}
