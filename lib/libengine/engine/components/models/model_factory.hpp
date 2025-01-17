#pragma once

#include <memory>
#include <utility>

namespace Engine::Components::Models {
    class ModelFactory {
      public:
        template <typename T, typename... TArgs>
        static auto make(TArgs&&... args) -> std::unique_ptr<T>;
    };

    template <typename T, typename... TArgs>
    auto ModelFactory::make(TArgs&&... args) -> std::unique_ptr<T> {
        auto model = std::make_unique<T>(std::forward<TArgs>(args)...);
        model->generate();
        return std::move(model);
    }
}