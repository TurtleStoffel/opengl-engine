#version 330 core
layout(triangles) in;
layout(triangle_strip, max_vertices=3) out;

in vec3 vertexColorVS[];
out vec4 vertexColor;

// std140 for explicit layout specification (for sharing)
layout(std140) uniform ModelViewProjection {
    mat4 model;
    mat4 view;
    mat4 projection;
};

uniform vec3 cameraPosition;

const vec3 lightDirection = normalize(vec3(0.4, 1.0, -0.8));
const vec3 lightColor = vec3(1.0, 0.6, 0.6);
const float reflectivity = 0.2;
const float shineDamper = 14.0;
const float ambientLighting = 0.3;

vec3 calculateTriangleNormal(vec3 p1, vec3 p2, vec3 p3) {
    vec3 tangent = p2 - p1;
    vec3 bitangent = p3 - p1;
    vec3 normal = cross(tangent, bitangent);
    return normalize(normal);
}

vec3 calculateSpecular(vec4 worldPosition, vec3 normal) {
    vec3 viewVector = normalize(cameraPosition - worldPosition.xyz);
    vec3 reflectedLightDirection = reflect(lightDirection, normal);
    if(dot(reflectedLightDirection, normal) > 0) {
        float specularFactor = dot(reflectedLightDirection, viewVector);
        specularFactor = max(pow(specularFactor, shineDamper), 0.0);
        return lightColor * specularFactor * reflectivity;
    } else {
        return vec3(0.0, 0.0, 0.0);
    }
}

void main() {
    vec4 p1 = model * gl_in[0].gl_Position;
    vec4 p2 = model * gl_in[1].gl_Position;
    vec4 p3 = model * gl_in[2].gl_Position;


    vec3 normal = calculateTriangleNormal(p1.xyz, p2.xyz, p3.xyz);
    // Brightness is factor in [0, 1] (dotproduct of normalized vectors)
    float brightness = max(dot(-lightDirection, normal), ambientLighting);
    vec3 color = vertexColorVS[0] * brightness;

    gl_Position = projection * view * p1;
    vertexColor = vec4(color, 0.0);
    //vertexColor = vec4(color + calculateSpecular(view * p1, normal), 0.0);
    EmitVertex();

    gl_Position = projection * view * p2;
    EmitVertex();

    gl_Position = projection * view * p3;
    EmitVertex();

    EndPrimitive();
}
