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

const vec3 lightDirection = normalize(vec3(0.4, 1.0, -0.8));
const float ambientLighting = 0.3;

void main() {
    // Transform Vertex Position/Normal from Local to World Space
    worldPosition = model * vec4(vPosition, 1.0f);
    vec4 worldNormal = model * vec4(vNormal, 0.0f);
    // Transform Vertex Position from World to Screen Space
    gl_Position = projection * view * worldPosition;

    // Calculate color of the Vertex
    // Brightness is factor in [0, 1] (dotproduct of normalized vectors)
    float brightness = max(dot(-lightDirection, worldNormal.xyz), ambientLighting);
    vertexColor = vColor * brightness;
}