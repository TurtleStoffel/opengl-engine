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
    void addCallback(std::function<void(T)> callback) {
        _callbacks.push_back(callback);
    }

    /**
     * Return value stored in Property
     */
    T value() {
        return _value;
    }

    /**
     * If value has been changed, call all callbacks with new value
     */
    void set(const T newValue) {
        if (_value != newValue) {
            _value = newValue;

            for (std::function<void(T)> callback : _callbacks) {
                callback(newValue);
            }
        }
    }

   private:
    T _value;
    std::vector<std::function<void(T)>> _callbacks;
};

#endif
