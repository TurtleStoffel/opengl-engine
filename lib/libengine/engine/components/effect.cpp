#include "engine/components/effect.hpp"

#include <utility>

namespace Engine::Components {
    Effect::Effect(Entity& entity)
          : Component{entity, "Effect"} {
    }
}