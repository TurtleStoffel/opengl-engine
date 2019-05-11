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
     *   fooProperty.addCallback(std::bind(&Object::method, this, std::placeholders::_1));
     */
    void addCallback(std::function<void(T)> callback) {
        _callbacks.push_back(callback);
    }

    /**
     * Add new generic callback (one that does not require the new value) to Property
     *
     * Example usage:
     *   fooProperty.addCallback(std::bind(&Object::method, this));
     */
    void addGenericCallback(std::function<void()> callback) {
        _genericCallbacks.push_back(callback);
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

            // Call callbacks which expect the new Property value
            for (std::function<void(T)> callback : _callbacks) {
                callback(newValue);
            }
            // Call generic callbacks which expect no value
            for (std::function<void()> callback : _genericCallbacks) {
                callback();
            }
        }
    }

   private:
    T _value;

    // List of callbacks that automatically get the new value
    std::vector<std::function<void(T)>> _callbacks;
    // List of callbacks that are generic methods that accept no arguments
    std::vector<std::function<void()>> _genericCallbacks;
};

#endif
