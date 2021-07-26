#include "engine/components/gui/sun_configuration_gui.hpp"

#include "engine/components/model.hpp"
#include "engine/components/state/sun_state.hpp"
#include "engine/objects/entity.hpp"

#include "imgui.h"

namespace Engine::Components::Gui {
    auto SunConfigurationGui::render() -> void {
        auto& sunState = m_entity.getRequired<SunState>();

        ImGui::Begin("Sun Configuration");
        if (ImGui::SliderInt("Temperature", &sunState.m_temperature, 3190, 17000)) {
            auto& model = m_entity.getRequired<Model>();
            model.generate();
        }
        ImGui::End();
    }
}