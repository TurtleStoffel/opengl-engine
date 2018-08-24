#ifndef FLATCAMERA_HPP
#define FLATCAMERA_HPP

#include "camera.hpp"

class FlatCamera : public Camera {
   public:
    FlatCamera(GLuint shader);
    virtual ~FlatCamera();

    virtual void handleInput(SDL_Event event);

   protected:
    virtual bool _update(int t);
};

#endif
