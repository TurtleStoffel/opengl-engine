#version 330 core

out vec4 colorOut;

float rand(vec2 co) {
    return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
}

void main() {
    float randomValue = rand(gl_FragCoord.xy);
    if(randomValue > 0.995) {
        colorOut = vec4(randomValue, randomValue, randomValue, 1.0);
    } else {
        colorOut = vec4(0.0, 0.0, 0.2, 1.0);
    }
}