#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <string>
#include <utility>

namespace components {
    class Component {
    public:
        Component();

        explicit Component(std::string component_name);

        [[nodiscard]] const std::string &get_name() const;

        virtual ~Component() = default;

    private:
        std::string name_;
    };
}  // namespace components

#endif