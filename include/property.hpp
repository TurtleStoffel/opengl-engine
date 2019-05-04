#ifndef PROPERTY_HPP
#define PROPERTY_HPP

#include <functional>
#include <vector>

template <typename T>
class Property {
   public:
    /**
     * Add new callback to Property
     *
     * Example usage:
     *   fooProperty.addCallback([this] {
     *     this->_rerender();
     *   })
     */
    void addCallback(std::function<void()> callback) {
        _callbacks.push_back(callback);
    }

    T value() {
        return _value;
    }

    /**
     * Operator overloading that automatically calls all callbacks when value is changed
     */
    T& operator=(const T& other) {
        _value = other;

        for (std::function<void()> callback : _callbacks) {
            callback();
        }

        return _value;
    }

   private:
    T _value;
    std::vector<std::function<void()>> _callbacks;
};

#endif
