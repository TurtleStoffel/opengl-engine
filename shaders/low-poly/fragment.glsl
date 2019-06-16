#version 330 core
out vec4 fColor;

flat in vec4 vertexColor;

void main() {
    fColor = vertexColor;
}
