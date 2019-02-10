#ifndef FLATCAMERA_HPP
#define FLATCAMERA_HPP

#include "camera.hpp"

#include "systemscene.hpp"

class FlatCamera : public Camera {
    // Only allow SystemScene to create an instance of FlatCamera
    friend class SystemScene;

   public:
    virtual ~FlatCamera();

    // Abstract Camera function
    virtual bool handleInput(SDL_Event event);

   protected:
    // Abstract Camera function
    virtual bool _update(int t);

   private:
    FlatCamera();
    static Camera* changeInstance();

    const float _speed = 0.001f;
};

#endif
