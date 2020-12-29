#pragma once

#include <functional>
#include <memory>
#include <vector>

template <typename T>
class TreeNode {
  public:
    explicit TreeNode(const T* parent);
    virtual ~TreeNode() = default;

    virtual auto visit(std::function<void(const T&)> callback) -> void;

  protected:
    virtual auto visitImpl(std::function<void(const T&)> callback) -> void = 0;

    const T* m_parent;
    std::vector<std::unique_ptr<T>> m_children;
};

template <typename T>
TreeNode<T>::TreeNode(const T* parent) : m_parent{parent} {
}

template <typename T>
auto TreeNode<T>::visit(std::function<void(const T&)> callback) -> void {
    visitImpl(callback);

    for (auto& child : m_children) {
        child->visit(callback);
    }
}