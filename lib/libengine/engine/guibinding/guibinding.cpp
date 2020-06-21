#include "guibinding.hpp"

#include "application.hpp"
#include "gui/propertytextfield.hpp"

GuiBinding::GuiBinding(const Object* pObject) {
    _pObject = pObject;

    // Create new Panel instance which has no Parent
    _pPanel = std::make_shared<gui::Panel>(nullptr);

    // Add a new TextField to the Panel for every Property in the PropertyMap of _pObject
    const std::map<std::string, AbstractProperty*> propertyMap = _pObject->getPropertyMap();
    for (const std::pair<const std::string, AbstractProperty*> kv : propertyMap) {
        // Create new PropertyTextField with the newly created panel as parent
        std::unique_ptr<gui::PropertyTextField>
            textField = std::make_unique<gui::PropertyTextField>(_pPanel.get(),
                                                                 kv.second,
                                                                 kv.first);
        // Give ownership to Panel (which is owned by this Object)
        _pPanel->addChild(std::move(textField));
    }
}

GuiBinding::~GuiBinding() {
    // Empty Virtual Destructor
}

void GuiBinding::changeSelected(bool selected) {
    if (selected) {
        Application::instance()->getGui()->setSelectedPanel(_pPanel);
    } else {
        Application::instance()->getGui()->setSelectedPanel(nullptr);
    }
}
