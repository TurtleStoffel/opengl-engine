#ifndef FLATCAMERA_HPP
#define FLATCAMERA_HPP

#include "camera.hpp"

class FlatCamera : public Camera {
   public:
    FlatCamera(GLuint shader);

   protected:
    virtual bool _handleInput(SDL_Event event);
};

#endif
