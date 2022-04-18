#pragma once

#include "engine/camera.hpp"
#include "engine/entity/entity.hpp"
#include "engine/opengl.hpp"
#include "engine/shaderregistry.hpp"
#include "engine/system/rendering.hpp"

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

        auto addEntity(std::unique_ptr<Entity> entity) -> void;
        auto getEntities() -> const std::vector<std::unique_ptr<Entity>>&;
        auto clearEntities() -> void;

        Camera m_camera;
        ShaderRegistry& m_shaderRegistry;

      private:
        auto mousePick(SDL_Event event) -> void;

        std::vector<std::unique_ptr<Entity>> m_entities;
        System::Rendering m_renderingSystem;
    };
}