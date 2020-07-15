#pragma once

class GuiBinding {
  public:
    virtual ~GuiBinding(){};

    virtual void render() const = 0;
};