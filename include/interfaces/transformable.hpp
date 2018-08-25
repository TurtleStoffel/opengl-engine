#ifndef TRANSFORMABLE_HPP
#define TRANSFORMABLE_HPP

class Transformable {
   public:
    virtual void scale(glm::vec3 v)     = 0;
    virtual void translate(glm::vec3 v) = 0;
    /**
     * Rotation is always assumed to be around z-axis
     */
    virtual void rotate(float degrees) = 0;
};

#endif
