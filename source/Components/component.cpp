#include <utility>

#include "Components/component.hpp"

namespace components {
    Component::Component() : name_("Component") {}

    Component::Component(std::string component_name) : name_(std::move(component_name)) {}
}  // namespace components