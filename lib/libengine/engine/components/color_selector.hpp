#pragma once

#include "engine/components/component.hpp"

#include <string>
#include <vector>

#include <glm/glm.hpp>

namespace Engine::Components {
    class ColorSelector final : public Component {

        class ColorSelectorLine {
          public:
            explicit ColorSelectorLine(int index);
            auto render() -> void;

            auto getColor() -> glm::vec3;

            auto getIndex() -> int;
            auto isDeleted() -> bool;
            auto isUpdated() -> bool;

            auto setMinimumHeight(float height) -> void;
            auto getHeight() -> float;

          private:
            glm::vec3 m_color;
            float m_height;

            int m_index;
            bool m_deleted{false};
            bool m_updated{false};

            std::string m_colorEditLabel;
            std::string m_deleteButtonLabel;
            std::string m_dragFloatLabel;
        };

      public:
        explicit ColorSelector(Entity& entity);
        ~ColorSelector() override = default;

        auto renderConfiguration() -> void final;

        auto getColor(float height) -> glm::vec3;

      private:
        auto makeConsistent() -> void;

        std::vector<ColorSelectorLine> m_selectorLines;
    };
}