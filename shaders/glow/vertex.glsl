#version 330 core
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec3 color;

// std140 for explicit layout specification (for sharing)
layout(std140) uniform ModelViewProjection{
    mat4 model;
    mat4 view;
    mat4 projection;
};

out float vertexFactor;
out vec3 vertexColor;

void main() {
    vec3 viewAngle = vec3(view[2][0], view[2][1], view[2][2]);
    vec3 worldNormal = (view * model * vec4(normal, 0.0f)).xyz;
    vertexFactor = clamp(dot(normalize(worldNormal), normalize(viewAngle)), 0.0f, 1.0f);

    vec3 offset = normal * 1.0f;
    gl_Position = projection * view * model * vec4(position + offset, 1.0f);
    vertexColor = color;
}