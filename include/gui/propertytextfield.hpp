#ifndef PROPERTYTEXTFIELD_HPP
#define PROPERTYTEXTFIELD_HPP

#include "gui/textfield.hpp"
#include "property.hpp"

namespace gui {

class PropertyTextField : public TextField {
   public:
    PropertyTextField(GuiObject* pParent, AbstractProperty* pProperty, const std::string name);

   private:
    void retrieveContentFromProperty();

    // Hide the setContent method from the outside world
    using TextField::setContent;

    AbstractProperty* _pProperty;
    const std::string _name;
};

}  // namespace gui

#endif
