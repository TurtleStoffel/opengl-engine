#pragma once

#include <cstddef>
#include <functional>
#include <memory>
#include <vector>

template <typename T>
class TreeNode {
  public:
    explicit TreeNode(const T* parent);
    virtual ~TreeNode() = default;

    virtual auto visit(std::function<void(const T&)> callback) -> void;

    virtual auto getDepth() const -> std::size_t;

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

template <typename T>
auto TreeNode<T>::getDepth() const -> std::size_t {
    if (m_parent) {
        return m_parent->getDepth() + 1;
    } else {
        return 1;
    }
}