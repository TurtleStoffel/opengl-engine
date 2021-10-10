#include "planetscene.hpp"

#include "engine/objects/planet.hpp"

PlanetScene::PlanetScene(Engine::ShaderRegistry& shaderRegistry)
      : Scene{shaderRegistry} {
    m_entities.push_back(Engine::Planet::createDefault(0.0f, 3.0f, m_shaderRegistry));
}
