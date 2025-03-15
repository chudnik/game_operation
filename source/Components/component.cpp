#include "Components/component.hpp"

namespace components {
    Component::Component() : name_("Component") {}

    Component::Component(std::string component_name) : name_(std::move(component_name)) {}

    const std::string &Component::get_name() const { return name_; }
}  // namespace components