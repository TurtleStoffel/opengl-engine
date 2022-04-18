#include "engine/components/color_selector.hpp"

#include "engine/color.hpp"
#include "engine/entities/entity.hpp"

#include "imgui.h"

#include <algorithm>
#include <cstddef>

namespace Engine::Components {
    ColorSelector::ColorSelectorLine::ColorSelectorLine(int index)
          : m_index{index}
          , m_colorEditLabel{"Test Color Picker##" + std::to_string(m_index)}
          , m_deleteButtonLabel{"Remove##" + std::to_string(m_index)}
          , m_dragFloatLabel{"Height##" + std::to_string(m_index)} {
    }

    auto ColorSelector::ColorSelectorLine::render() -> void {
        if (ImGui::DragFloat(m_dragFloatLabel.c_str(), &m_height, 0.01f, 0.0f, 1.0f)) {
            m_updated = true;
        }
        ImGui::SameLine();
        if (ImGui::ColorEdit3(m_colorEditLabel.c_str(),
                              &m_color[0],
                              ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel)) {
            m_updated = true;
        }
        ImGui::SameLine();
        if (ImGui::Button(m_deleteButtonLabel.c_str())) {
            m_updated = true;
            m_deleted = true;
        }
    }

    auto ColorSelector::ColorSelectorLine::getColor() -> glm::vec3 {
        return m_color;
    }

    auto ColorSelector::ColorSelectorLine::getIndex() -> int {
        return m_index;
    }

    auto ColorSelector::ColorSelectorLine::isDeleted() -> bool {
        return m_deleted;
    }

    auto ColorSelector::ColorSelectorLine::isUpdated() -> bool {
        auto result = m_updated;
        m_updated   = false;
        return result;
    }

    auto ColorSelector::ColorSelectorLine::setMinimumHeight(float height) -> void {
        if (m_height < height) {
            m_height = height;
        }
    }

    auto ColorSelector::ColorSelectorLine::getHeight() -> float {
        return m_height;
    }

    ColorSelector::ColorSelector(Entity& entity)
          : Component{entity, "Color Selector"} {
        m_selectorLines.emplace_back(0);
    }

    auto ColorSelector::renderConfiguration() -> void {
        ImGui::Text("Color Selector");
        makeConsistent();
        for (auto& line : m_selectorLines) {
            line.render();
        }
        if (ImGui::Button("Add Line")) {
            auto newIndex = m_selectorLines.back().getIndex() + 1;
            m_selectorLines.emplace_back(newIndex);
        }
    }

    auto ColorSelector::getColor(float height) -> glm::vec3 {
        for (auto i = std::size_t{0}; i < m_selectorLines.size(); i++) {
            if (m_selectorLines[i].getHeight() > height) {
                if (i == 0) {
                    return m_selectorLines[i].getColor();
                }

                auto color1   = m_selectorLines[i - 1].getColor();
                auto color2   = m_selectorLines[i].getColor();
                auto fraction = (height - m_selectorLines[i - 1].getHeight()) /
                                (m_selectorLines[i].getHeight() -
                                 m_selectorLines[i - 1].getHeight());

                return Color::interpolate(color1, color2, fraction);
            }
        }

        return m_selectorLines.back().getColor();
    }

    auto ColorSelector::makeConsistent() -> void {
        m_selectorLines.erase(std::remove_if(m_selectorLines.begin(),
                                             m_selectorLines.end(),
                                             [](auto& line) { return line.isDeleted(); }),
                              m_selectorLines.end());

        auto update        = false;
        auto minimumHeight = 0.0f;
        for (auto& line : m_selectorLines) {
            if (line.isUpdated()) {
                update = true;
            }
            line.setMinimumHeight(minimumHeight);
            minimumHeight = line.getHeight();
        }

        if (update) {
            auto& model = m_entity.getRequired<Model>();
            model.generate();
        }
    }
}