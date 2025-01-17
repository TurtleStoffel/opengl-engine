#include "systemscene.hpp"

#include "engine/components/gui/star_gui.hpp"
#include "engine/components/gui_component.hpp"
#include "engine/components/script.hpp"
#include "engine/components/scripts/planet_rotation.hpp"
#include "engine/entities/background.hpp"
#include "engine/entities/planet.hpp"
#include "engine/entities/star.hpp"
#include "engine/random.hpp"

#include <utility>

SystemScene::SystemScene(Engine::Shaders::Registry& shaderRegistry)
      : Scene{shaderRegistry} {
    addEntity(Engine::Background::createDefault(m_shaderRegistry));
    // Create objects
    auto star = Engine::Star::createDefault(m_shaderRegistry);
    star->getRequired<Engine::Components::GuiComponent>().addSubcomponent(
        std::make_unique<Engine::Components::Gui::StarGui>(*star));
    addEntity(std::move(star));

    float minPlanetOffset = 2.0f;
    float maxPlanetOffset = 3.0f;
    float minPlanetRadius = 0.3f;
    float maxPlanetRadius = 0.8f;

    float currentPlanetOffset = 3.0f;

    for (int i = 0; i < Engine::Random::randi(1, 3); i++) {
        currentPlanetOffset += Engine::Random::randf(minPlanetOffset, maxPlanetOffset);
        float planetRadius = Engine::Random::randf(minPlanetRadius, maxPlanetRadius);

        auto planet = Engine::Planet::createDefault(currentPlanetOffset,
                                                    planetRadius,
                                                    m_shaderRegistry);
        planet->registerComponent<Engine::Components::Script>(
            std::make_unique<Engine::Components::Scripts::PlanetRotation>(*planet));

        addEntity(std::move(planet));
    }
}
