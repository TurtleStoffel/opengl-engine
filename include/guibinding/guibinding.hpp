#ifndef GUIBINDING_HPP
#define GUIBINDING_HPP

#include "objects/object.hpp"

class GuiBinding {
   public:
    GuiBinding(Object* pObject) {
        _pObject = pObject;
    };
    virtual ~GuiBinding(){};

    virtual void render() = 0;

   protected:
    Object* _pObject;
};

#endif
