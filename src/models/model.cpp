#include "models/model.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "opengl.hpp"
#include "shadercontainer.hpp"

Model::Model(Transform* pTransform) : Model(pTransform, nullptr) {
}

Model::Model(Transform* pTransform, Property<bool>* selected) {
    _pTransform = pTransform;
    _selected   = selected;

    // Generate OpenGL buffers
    glGenVertexArrays(1, &_vao);
    glGenBuffers(1, &_vbo);
}

Model::~Model() {
    // Empty virtual destructor
}

void Model::render() {
    // Set Model Matrix in Shader
    _pTransform->passModelMatrixToShader();

    // Bind vertex data of current model
    glBindVertexArray(_vao);

    // Render silhouette if object is selected
    if (_selected && _selected->value()) {
        // Disable depth test to render to background
        glDisable(GL_DEPTH_TEST);
        // Render using Silhouette Shader
        ShaderContainer::silhouetteShader()->use();
        glDrawArrays(GL_TRIANGLES, 0, _vertices.size());
    }

    // Render object itself
    // Enable depth test to render object normally
    glEnable(GL_DEPTH_TEST);
    // Render using Low Poly Shader
    ShaderContainer::lowPolyShader()->use();
    glDrawArrays(GL_TRIANGLES, 0, _vertices.size());
}

void Model::_setupBuffers() {
    // Enable model VAO and VBO
    glBindVertexArray(_vao);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    // Upload data
    glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(Vertex), &_vertices[0], GL_STATIC_DRAW);

    // Get attribute information from vertices
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);
    // clang-format off
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
    glEnableVertexAttribArray(1);
    // clang-format on
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
    glEnableVertexAttribArray(2);

    // Disable VAO and VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
