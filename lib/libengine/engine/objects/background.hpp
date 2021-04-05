#pragma once

#include "engine/objects/object.hpp"

#include <memory>

class ShaderRegistry;

class Background : public Engine::Object {
  public:
    static auto createDefault(const ShaderRegistry& shaderRegistry) -> std::unique_ptr<Background>;

    Background();
    ~Background() override = default;
};