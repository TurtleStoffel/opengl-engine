#pragma once

namespace Engine::Random {
    // Float in range [0, 1[
    auto randf() -> float;
    // Float in range [min, max[
    auto randf(float min, float max) -> float;

    // Float in range [0, 2 Pi[
    auto randRadian() -> float;

    // Integer in range [min, max[
    auto randi(int min, int max) -> int;
    // Integer in range [0, max[
    auto randi(int max) -> int;
}