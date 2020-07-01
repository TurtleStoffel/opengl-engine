#include "bounds.hpp"

namespace gui {

Bounds::Bounds() {
    _xMin = 0;
    _yMin = 0;
    _xMax = 0;
    _yMax = 0;
}

Bounds::Bounds(float* bounds) {
    _xMin = bounds[0];
    _yMin = bounds[1];
    _xMax = bounds[2];
    _yMax = bounds[3];
}

void Bounds::contain(Bounds bounds) {
    _fitWidth(bounds);
    _fitHeight(bounds);
}

float Bounds::getWidth() {
    return _xMax - _xMin;
}

float Bounds::getHeight() {
    return _yMax - _yMin;
}

float Bounds::getXMin() {
    return _xMin;
}

float Bounds::getYMin() {
    return _yMin;
}

float Bounds::getXMax() {
    return _xMax;
}

float Bounds::getYMax() {
    return _yMax;
}

void Bounds::_fitWidth(Bounds bounds) {
    if (bounds.getXMin() < _xMin) {
        _xMin = bounds.getXMin();
    }
    if (bounds.getXMax() > _xMax) {
        _xMax = bounds.getXMax();
    }
}

void Bounds::_fitHeight(Bounds bounds) {
    if (bounds.getYMin() < _yMin) {
        _yMin = bounds.getYMin();
    }
    if (bounds.getYMax() > _yMax) {
        _yMax = bounds.getYMax();
    }
}

} // namespace gui