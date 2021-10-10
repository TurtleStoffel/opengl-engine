#pragma once

#include "engine/camera.hpp"
#include "engine/objects/entity.hpp"
#include "engine/opengl.hpp"
#include "engine/shaderregistry.hpp"

#include <vector>

namespace Engine {
    class Scene {
      public:
        Scene(ShaderRegistry& shaderRegistry);
        virtual ~Scene() = default;

        auto update(int dt) -> void;
        auto render() -> void;

        auto handleInput(SDL_Event event) -> bool;
        auto setWindowSize(int windowWidth, int windowHeight) -> void;

      protected:
        virtual auto renderGui() -> void;

        std::vector<std::unique_ptr<Engine::Entity>> m_entities;
        std::unique_ptr<Camera> m_camera;

        ShaderRegistry& m_shaderRegistry;

      private:
        auto mousePick(SDL_Event event) -> void;
    };
}