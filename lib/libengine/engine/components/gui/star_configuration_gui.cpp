#include "engine/components/gui/star_configuration_gui.hpp"

#include "engine/components/model.hpp"
#include "engine/components/state/star_state.hpp"
#include "engine/entity/entity.hpp"

#include "imgui.h"

namespace Engine::Components::Gui {
    auto StarConfigurationGui::render() -> void {
        auto& starState = m_entity.getRequired<StarState>();

        ImGui::Begin("Star Configuration");
        if (ImGui::SliderInt("Temperature", &starState.m_temperature, 3190, 17000)) {
            auto& model = m_entity.getRequired<Model>();
            model.generate();
        }
        ImGui::End();
    }
}