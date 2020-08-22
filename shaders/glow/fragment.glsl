#version 330 core
in float vertexFactor;
in vec3 vertexColor;

void main() {
    float alpha = clamp(pow(vertexFactor, 10.0f), 0.0f, 1.0f);
    gl_FragColor = vec4(vertexColor, alpha);
}