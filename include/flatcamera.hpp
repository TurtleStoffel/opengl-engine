#ifndef FLATCAMERA_HPP
#define FLATCAMERA_HPP

#include "camera.hpp"

class FlatCamera : public Camera {
   public:
    virtual ~FlatCamera();

    // Abstract Camera function
    virtual void handleInput(SDL_Event event);

   protected:
    // Abstract Camera function
    virtual bool _update(int t);
};

#endif
