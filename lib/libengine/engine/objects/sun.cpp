#include "sun.hpp"

#include <memory>

#include "guibinding/sunguibinding.hpp"

#include "color.hpp"
#include "models/sphere.hpp"

Sun::Sun() {
    _pModel = std::make_unique<Sphere>(_pTransform.get(), color::yellow);

    _pGuiBinding = std::make_unique<SunGuiBinding>(this);
}

void Sun::update(int t) {
}
