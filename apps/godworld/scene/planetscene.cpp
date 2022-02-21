#include "planetscene.hpp"

#include "engine/entity/planet.hpp"

PlanetScene::PlanetScene(Engine::ShaderRegistry& shaderRegistry)
      : Engine::Scene{shaderRegistry} {
    addEntity(Engine::Planet::createDefault(0.0f, 3.0f, m_shaderRegistry));
}
