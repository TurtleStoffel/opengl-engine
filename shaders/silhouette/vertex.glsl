#version 330 core
layout(location = 0) in vec3 vPosition;
layout(location = 1) in vec3 vNormal;

// std140 for explicit layout specification (for sharing)
layout(std140) uniform ModelViewProjection {
    mat4 model;
    mat4 view;
    mat4 projection;
};

out vec3 outputColor;

const float OFFSET = 0.02f;

void main() {
    gl_Position = projection * view * model * vec4(vPosition + vNormal*OFFSET, 1.0f);
    outputColor = vec3(0.0f, 0.0f, 0.0f);
}
