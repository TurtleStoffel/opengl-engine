#include "engine/components/gui/composite_gui.hpp"

#include <utility>

namespace Engine::Components::Gui {
    auto CompositeGui::render() -> void {
        for (auto& subcomponent : m_subcomponents) {
            subcomponent->render();
        }
    }

    auto CompositeGui::addSubcomponent(std::unique_ptr<GuiComponent> subcomponent) -> void {
        m_subcomponents.push_back(std::move(subcomponent));
    }
}