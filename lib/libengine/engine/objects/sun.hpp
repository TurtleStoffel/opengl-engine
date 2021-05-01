#pragma once

#include "engine/objects/entity.hpp"

#include <memory>

class ShaderRegistry;

namespace Engine::Components::Gui {
    class SunConfigurationGui;
    class SunGui;
}

class Sun : public Engine::Entity {
    friend class Engine::Components::Gui::SunGui;
    friend class Engine::Components::Gui::SunConfigurationGui;

  public:
    static auto createDefault(const ShaderRegistry& shaderRegistry) -> std::unique_ptr<Sun>;

    Sun();
    ~Sun() override = default;

  private:
    // Used by SunConfigurationGui
    auto generateModel() -> void;

    // Temperature in Kelvin
    int m_temperature = 6000;
};