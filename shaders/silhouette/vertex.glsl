#version 330 core
layout(location = 0) in vec3 vPosition;
layout(location = 1) in vec3 vNormal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 outputColor;

const float OFFSET = 0.1f;

void main() {
    gl_Position = projection * view * model * vec4(vPosition + vNormal*OFFSET, 1.0f);
    outputColor = vec3(0.0f, 0.0f, 0.0f);
}
