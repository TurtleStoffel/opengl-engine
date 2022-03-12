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

// Settlement related input
uniform vec3 localSettlementPosition;
flat out vec4 settlementPosition;

out vec4 worldPosition;

// force flat shading
flat out vec3 vertexColor;

const vec4 starLocation = vec4(0.0, 0.0, 0.0, 1.0);
const float ambientLighting = 0.35;

void main() {
    // Transform Vertex Position/Normal from Local to World Space
    worldPosition = model * vec4(vPosition, 1.0f);
    vec4 worldNormal = model * vec4(vNormal, 0.0f);
    // Transform Vertex Position from World to Screen Space
    gl_Position = projection * view * worldPosition;

    vec4 lightDirection = worldPosition - starLocation;

    // Calculate color of the Vertex
    // Brightness is factor in [0, 1] (dotproduct of normalized vectors)
    float brightness = max(dot(-lightDirection.xyz, worldNormal.xyz)*0.72f, ambientLighting);
    vertexColor = vColor * brightness;
}