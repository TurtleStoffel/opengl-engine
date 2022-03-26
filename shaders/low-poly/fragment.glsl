#version 330 core
out vec4 fColor;

flat in vec3 vertexColor;
in vec4 worldPosition;

float rand(vec2 co){
    return fract(sin(dot(co, vec2(12.9898, 78.233))) * 43758.5453);
}

void main() {
    // Add a little bit of noise to the color
    vec3 updatedVertexColor = vertexColor + vec3(0.02f, 0.02f, 0.02f)*rand(worldPosition.xy/10);

    fColor = vec4(updatedVertexColor, 1.0);
}