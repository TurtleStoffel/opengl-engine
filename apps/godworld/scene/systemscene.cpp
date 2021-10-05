#include "systemscene.hpp"

#include "engine/components/gui/star_gui.hpp"
#include "engine/components/gui_component.hpp"
#include "engine/components/script.hpp"
#include "engine/components/scripts/planet_rotation.hpp"
#include "engine/objects/background.hpp"
#include "engine/objects/planet.hpp"
#include "engine/objects/star.hpp"
#include "engine/util.hpp"

#include <utility>

SystemScene::SystemScene(const Engine::ShaderRegistry& shaderRegistry)
      : Scene{shaderRegistry} {
    m_entities.push_back(Engine::Background::createDefault(m_shaderRegistry));
    // Create objects
    auto star = Engine::Star::createDefault(m_shaderRegistry);
    star->getRequired<Engine::Components::GuiComponent>().addSubcomponent(
        std::make_unique<Engine::Components::Gui::StarGui>(*star));
    m_entities.push_back(std::move(star));

    float minPlanetOffset = 2.0f;
    float maxPlanetOffset = 3.0f;
    float minPlanetRadius = 0.3f;
    float maxPlanetRadius = 0.8f;

    float currentPlanetOffset = 3.0f;

    for (int i = 0; i < util::randi(1, 3); i++) {
        currentPlanetOffset += util::randf(minPlanetOffset, maxPlanetOffset);
        float planetRadius = util::randf(minPlanetRadius, maxPlanetRadius);

        auto planet = Engine::Planet::createDefault(currentPlanetOffset,
                                                    planetRadius,
                                                    m_shaderRegistry);
        planet->registerComponent<Engine::Components::Script>(
            std::make_unique<Engine::Components::Scripts::PlanetRotation>(*planet));

        m_entities.push_back(std::move(planet));
    }
}
