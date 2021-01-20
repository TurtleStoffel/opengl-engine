#version 330 core
out vec4 fColor;

uniform vec3 circlePosition;

flat in vec3 vertexColor;
in vec4 worldPosition;

void main() {
    if(distance(worldPosition.xyz, circlePosition) < 0.5) {
        fColor = vec4(vertexColor*0.3, 1.0);
    } else {
        fColor = vec4(vertexColor, 1.0);
    }
}