#version 330 core
out vec4 fColor;

flat in vec3 vertexColor;
in vec4 worldPosition;

float rand(vec2 co){
    return fract(sin(dot(co, vec2(12.9898, 78.233))) * 43758.5453);
}

void main() {
    vec3 vertexColorWithNoise = vertexColor + vec3(0.15f, 0.15f, 0.15f)*rand(worldPosition.xy/20);

    fColor = vec4(vertexColorWithNoise, 1.0);
}