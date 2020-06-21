#include "propertytextfield.hpp"

namespace gui {

PropertyTextField::PropertyTextField(GuiObject* pParent, AbstractProperty* pProperty,
                                     const std::string name)
    : TextField(pParent), _name(name) {
    _pProperty = pProperty;
    _pProperty->addGenericCallback(
        std::bind(&PropertyTextField::retrieveContentFromProperty, this));

    // Make sure content is set even when value does not change
    retrieveContentFromProperty();
}

void PropertyTextField::retrieveContentFromProperty() {
    setContent(_name + "\t" + _pProperty->getString());
}

} // namespace gui