#pragma once

namespace gui {

class Bounds {
  public:
    Bounds();
    Bounds(float* bounds);

    void contain(Bounds bounds);

    float getWidth();
    float getHeight();

    float getXMin();
    float getXMax();
    float getYMin();
    float getYMax();

  private:
    float _xMin;
    float _yMin;
    float _xMax;
    float _yMax;

    void _fitWidth(Bounds bounds);
    void _fitHeight(Bounds bounds);
};

} // namespace gui