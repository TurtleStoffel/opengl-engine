#include "scene/scene.hpp"

namespace ModelEditor {
    Scene::Scene(Engine::Shaders::Registry& shaderRegistry)
          : Engine::Scene{shaderRegistry} {
    }
}