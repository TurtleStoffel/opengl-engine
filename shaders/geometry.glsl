#version 330 core
layout(triangles) in;
layout(triangle_strip, max_vertices=3) out;

in vec3 vertexColorVS[];
out vec4 vertexColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec3 cameraPosition;

const vec3 lightDirection = normalize(vec3(0.4, -1.0, 0.8));
const vec3 lightColor = vec3(1.0, 0.6, 0.6);
const float reflectivity = 0.2;
const float shineDamper = 14.0;
const float ambientLighting = 0.5;

vec3 calculateTriangleNormal() {
    vec3 tangent = gl_in[1].gl_Position.xyz - gl_in[0].gl_Position.xyz;
    vec3 bitangent = gl_in[2].gl_Position.xyz - gl_in[0].gl_Position.xyz;
    vec3 normal = cross(tangent, bitangent);
    return normalize(normal);
}

vec3 calculateSpecular(vec4 worldPosition, vec3 normal) {
    vec3 viewVector = normalize(cameraPosition - worldPosition.xyz);
    vec3 reflectedLightDirection = reflect(lightDirection, normal);
    float specularFactor = dot(reflectedLightDirection, viewVector);
    specularFactor = max(pow(specularFactor, shineDamper), 0.0);
    return lightColor * specularFactor * reflectivity;
}

void main() {
    vec3 normal = calculateTriangleNormal();
    float brightness = max(dot(-lightDirection, normal), ambientLighting);
    vec3 color = vertexColorVS[0] * brightness;

    vec4 worldPosition = gl_in[0].gl_Position;
    gl_Position = projection * view * model * worldPosition;
    vertexColor = vec4(color + calculateSpecular(worldPosition, normal), 0.0);
    EmitVertex();

    worldPosition = gl_in[1].gl_Position;
    gl_Position = projection * view * model * worldPosition;
    EmitVertex();

    worldPosition = gl_in[2].gl_Position;
    gl_Position = projection * view * model * worldPosition;
    EmitVertex();

    EndPrimitive();
}
