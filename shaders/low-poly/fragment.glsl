#version 330 core
out vec4 fColor;

uniform bool isSettlementEnabled = false;
uniform vec4 settlementLocation = vec4(0.0, 1.0, 1.0, 1.0);

flat in vec3 vertexColor;
in vec4 worldPosition;

void main() {
    if(isSettlementEnabled && distance(worldPosition, settlementLocation) < 0.5) {
        fColor = vec4(vertexColor*0.3, 1.0);
    } else {
        fColor = vec4(vertexColor, 1.0);
    }
}
