#pragma once

#include "engine/objects/object.hpp"

#include <memory>

class GuiFactory;
class ShaderRegistry;

class Sun : public Engine::Entity {
    friend class SunGui;
    friend class SunConfigurationGui;

  public:
    static auto createDefault(GuiFactory& guiFactory, const ShaderRegistry& shaderRegistry)
        -> std::unique_ptr<Sun>;

    Sun(GuiFactory& guiFactory);
    ~Sun() override = default;

  private:
    // Used by SunConfigurationGui
    void _generateModel();

    // Temperature in Kelvin
    int m_temperature = 6000;
};