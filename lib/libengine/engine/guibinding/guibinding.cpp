#include "guibinding.hpp"

#include "imgui.h"

#include "application.hpp"

GuiBinding::GuiBinding(const Object* pObject) {
    _pObject = pObject;
}

void GuiBinding::render() const {
    ImGui::SetNextWindowSize(ImVec2(200.0f, 80.0f));
    ImGui::Begin("Planet Information");
    ImGui::Columns(2);
    const std::map<std::string, AbstractProperty*> propertyMap = _pObject->getPropertyMap();
    for (const std::pair<const std::string, AbstractProperty*> kv : propertyMap) {
        ImGui::Text("%s", kv.first.c_str());
        ImGui::NextColumn();
        ImGui::Text("%s", kv.second->getString().c_str());
        ImGui::NextColumn();
    }
    ImGui::Columns(1);
    ImGui::End();
}