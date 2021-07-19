#pragma once

#include "engine/objects/entity.hpp"

#include <memory>

class ShaderRegistry;

namespace Engine::Components::Gui {
    class SunConfigurationGui;
    class SunGui;
}

namespace Engine {
    class Sun : public Entity {
        friend class Components::Gui::SunGui;
        friend class Components::Gui::SunConfigurationGui;

      public:
        static auto createDefault(const ShaderRegistry& shaderRegistry) -> std::unique_ptr<Sun>;

        Sun();
        ~Sun() override = default;

      private:
        // Temperature in Kelvin
        int m_temperature = 6000;
    };
}