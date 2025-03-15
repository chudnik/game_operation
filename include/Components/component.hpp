#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <string>

namespace components {
    class Component {
    private:
        std::string name_;

    public:
        Component();

        explicit Component(std::string component_name);

        virtual ~Component() = default;
    };
}  // namespace components

#endif