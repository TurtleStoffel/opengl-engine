#include "shadercontainer.hpp"

#include <glm/glm.hpp>

ShaderContainer* ShaderContainer::_instance = nullptr;

ShaderContainer* ShaderContainer::instance() {
    assert(_instance);

    return _instance;
}

void ShaderContainer::init() {
    _instance = new ShaderContainer();
}

Shader* ShaderContainer::lowPolyShader() {
    assert(_instance);

    return _instance->_lowPolyShader;
}

Shader* ShaderContainer::silhouetteShader() {
    assert(_instance);

    return _instance->_silhouetteShader;
}

void ShaderContainer::setModelViewProjectionMatrix(void* model, void* view, void* projection) {
    glBindBuffer(GL_UNIFORM_BUFFER, _matrixUBO);

    if (model) {
        glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), model);
    }
    if (view) {
        glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), sizeof(glm::mat4), view);
    }
    if (projection) {
        glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4) * 2, sizeof(glm::mat4), projection);
    }

    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

ShaderContainer::ShaderContainer() {
    // Create shader programs
    _lowPolyShader = new Shader("../shaders/low-poly/vertex.glsl",
                                "../shaders/low-poly/geometry.glsl",
                                "../shaders/low-poly/fragment.glsl");

    _silhouetteShader = new Shader("../shaders/silhouette/vertex.glsl",
                                   "../shaders/silhouette/fragment.glsl");

    // Create uniform buffer object to store Model/View/Projection matrix
    glGenBuffers(1, &_matrixUBO);
    glBindBuffer(GL_UNIFORM_BUFFER, _matrixUBO);
    glBufferData(GL_UNIFORM_BUFFER, sizeof(glm::mat4) * 3, nullptr, GL_STREAM_DRAW);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);

    // Bind Uniform Block to Uniform Buffer Object
    GLuint bindingIndex     = 1;
    GLuint matrixBlockIndex = _lowPolyShader->getUniformBlockIndex("ModelViewProjection");
    // Bind shader block to index
    _lowPolyShader->uniformBlockBinding(matrixBlockIndex, bindingIndex);
    _silhouetteShader->uniformBlockBinding(matrixBlockIndex, bindingIndex);
    // Bind buffer to index
    glBindBufferRange(GL_UNIFORM_BUFFER, bindingIndex, _matrixUBO, 0, sizeof(glm::mat4) * 3);
}

ShaderContainer::~ShaderContainer() {
    delete _lowPolyShader;
    delete _silhouetteShader;
}
