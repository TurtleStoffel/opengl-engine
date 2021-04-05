#pragma once

#include "object.hpp"

#include <memory>

class GuiFactory;
class ShaderRegistry;

class Sun : public Object {
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
    int _temperature = 6000;
};