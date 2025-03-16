#ifndef POSITION_COMPONENT_HPP
#define POSITION_COMPONENT_HPP

#include "component.hpp"
#include <memory>

namespace components {
    class PositionComponent : public Component {
    public:
        PositionComponent();

        explicit PositionComponent(std::pair<unsigned, unsigned> position);

        explicit PositionComponent(unsigned x, unsigned y);

        explicit PositionComponent(std::string name);

        explicit PositionComponent(std::string name, std::pair<unsigned, unsigned> position);

        explicit PositionComponent(std::string name, unsigned x, unsigned y);

        [[nodiscard]] std::pair<unsigned, unsigned> get_position() const;

        [[nodiscard]] unsigned get_x() const;

        [[nodiscard]] unsigned get_y() const;

        void shift(unsigned x, unsigned y);

    private:
        std::pair<unsigned, unsigned> position_;
    };
}

#endif