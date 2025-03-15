#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <string>
#include <utility>

namespace components {
    class Component {
    private:
        std::string name_;

    public:
        Component();

        explicit Component(std::string component_name);

        [[nodiscard]] const std::string &get_name() const;

        virtual ~Component() = default;
    };
}  // namespace components

#endif