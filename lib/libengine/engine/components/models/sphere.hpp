#pragma once

#include "engine/color.hpp"
#include "engine/components/model.hpp"

#include <functional>
#include <map>

namespace Engine {
    class Entity;
}

namespace Engine::Components::Models {
    class Sphere : public Model {
      public:
        explicit Sphere(Entity& entity, std::function<glm::vec3(float)> colorGenerator,
                        int depth = 4);
        ~Sphere() override = default;

      private:
        auto generateImpl() -> void override;

        struct Face {
            unsigned int v1;
            unsigned int v2;
            unsigned int v3;
        };

        auto getMidpoint(unsigned int p1, unsigned int p2) -> unsigned int;
        auto createVertex(glm::vec3 point) -> unsigned int;

        int m_depth;

        // Index + 1 of the last created Vertex
        int m_vertexIndex = 0;

        /**
         * unsigned int can define 4.294.967.295 unique points
         * Key formula: (smallIndex << 32) + bigIndex
         * Original Vertices are not added to _midPointCache, so keys are unique
         *      (otherwise smallIndex 0 would lead to existing indices)
         */
        std::map<unsigned long, unsigned int> m_midPointCache;

        std::function<glm::vec3(float)> m_colorGenerator;
    };
}