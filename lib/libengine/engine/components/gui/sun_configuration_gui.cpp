#include "engine/components/gui/sun_configuration_gui.hpp"

#include "engine/objects/sun.hpp"

#include "imgui.h"

namespace Engine::Components::Gui {
    auto SunConfigurationGui::render() -> void {
        auto& sun = static_cast<Sun&>(m_entity);

        ImGui::Begin("Sun Configuration");
        if (ImGui::SliderInt("Temperature", &sun.m_temperature, 3190, 17000)) {
            sun._generateModel();
        }
        ImGui::End();
    }
}