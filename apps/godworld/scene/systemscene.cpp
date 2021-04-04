#include "systemscene.hpp"

#include "engine/application.hpp"
#include "engine/components/script.hpp"
#include "engine/components/scripts/planet_rotation.hpp"
#include "engine/objects/background.hpp"
#include "engine/objects/planet.hpp"
#include "engine/objects/sun.hpp"
#include "engine/util.hpp"

#include <utility>

SystemScene::SystemScene(const ShaderRegistry& shaderRegistry)
      : Scene{shaderRegistry} {
    m_objects.push_back(std::make_unique<Background>());
    // Create objects
    m_objects.push_back(std::make_unique<Sun>(m_guiFactory));
    float minPlanetOffset = 2.0f;
    float maxPlanetOffset = 3.0f;
    float minPlanetRadius = 0.3f;
    float maxPlanetRadius = 0.8f;

    float currentPlanetOffset = 3.0f;

    for (int i = 0; i < util::randi(1, 3); i++) {
        currentPlanetOffset += util::randf(minPlanetOffset, maxPlanetOffset);
        float planetRadius = util::randf(minPlanetRadius, maxPlanetRadius);

        auto planet = std::make_unique<Planet>(currentPlanetOffset, planetRadius);
        planet->registerComponent<Engine::Components::Script>(
            std::make_unique<Engine::Components::Scripts::PlanetRotation>(*planet));

        m_objects.push_back(std::move(planet));
    }
}
