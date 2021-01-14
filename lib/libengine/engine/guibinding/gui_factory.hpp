#pragma once

#include "engine/guibinding/guibinding.hpp"
#include "engine/guibinding/planet_gui.hpp"
#include "engine/guibinding/sun_configuration_gui.hpp"
#include "engine/guibinding/sun_gui.hpp"
#include "engine/objects/planet.hpp"
#include "engine/objects/sun.hpp"

#include <memory>
#include <type_traits>

class GuiFactory {
  public:
    enum class GuiType { CONFIGURATION, GAME };

    explicit GuiFactory(GuiType guiType);

    template <typename T>
    auto createGui(T& object) -> std::unique_ptr<GuiBinding>;

  private:
    template <typename T>
    auto createConfigurationGui(T& object) -> std::unique_ptr<GuiBinding>;
    template <typename T>
    auto createGameGui(T& object) -> std::unique_ptr<GuiBinding>;

    GuiType m_guiType;
};

template <typename T>
auto GuiFactory::createGui(T& object) -> std::unique_ptr<GuiBinding> {
    if (m_guiType == GuiType::CONFIGURATION) {
        return createConfigurationGui(object);
    }
    if (m_guiType == GuiType::GAME) {
        return createGameGui(object);
    }

    // Unreachable
    assert(false);
}

template <typename T>
auto GuiFactory::createConfigurationGui(T& object) -> std::unique_ptr<GuiBinding> {
    if constexpr (std::is_same_v<T, Sun>) {
        return std::make_unique<SunConfigurationGui>(object);
    }
    if constexpr (std::is_same_v<T, Planet>) {
        return std::make_unique<PlanetGui>(object);
    }

    // Unreachable
    assert(false);
}

template <typename T>
auto GuiFactory::createGameGui(T& object) -> std::unique_ptr<GuiBinding> {
    if constexpr (std::is_same_v<T, Sun>) {
        return std::make_unique<SunGui>(object);
    }
    if constexpr (std::is_same_v<T, Planet>) {
        return std::make_unique<PlanetGui>(object);
    }

    // Unreachable
    assert(false);
}