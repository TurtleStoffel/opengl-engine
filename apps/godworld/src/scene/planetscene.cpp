#include "planetscene.hpp"

#include "engine/entities/planet.hpp"

PlanetScene::PlanetScene(Engine::Shaders::Registry& shaderRegistry)
      : Engine::Scene{shaderRegistry} {
    addEntity(Engine::Planet::createDefault(0.0f, 3.0f, m_shaderRegistry));
}
