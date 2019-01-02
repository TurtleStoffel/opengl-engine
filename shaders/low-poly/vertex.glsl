#version 330 core
layout(location = 0) in vec3 vPosition;
layout(location = 1) in vec3 vNormal;
layout(location = 2) in vec3 vColor;

out vec3 vertexColorVS;

void main() {
    gl_Position = vec4(vPosition, 1.0f);
    vertexColorVS = vColor;
}
