#version 330 core
layout(location = 0) in vec3 vPosition;
layout(location = 1) in vec3 vNormal;
layout(location = 2) in vec3 vColor;

// std140 for explicit layout specification (for sharing)
layout(std140) uniform ModelViewProjection {
    mat4 model;
    mat4 view;
    mat4 projection;
};

out vec4 worldPosition;
flat out vec3 vertexColor;

void main() {
    worldPosition = model * vec4(vPosition, 1.0f);
    gl_Position = projection * view * worldPosition;

    vertexColor = vColor;
}