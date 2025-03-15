#include <utility>

#include "Components/position_component.hpp"

namespace components {
    PositionComponent::PositionComponent() :
            Component("Position-Component"),
            position_(0, 0) {}

    PositionComponent::PositionComponent(const unsigned x, const unsigned y) :
            Component("Position-Component"),
            position_(x, y) {}

    PositionComponent::PositionComponent(std::pair<unsigned, unsigned> position) :
            Component("Position-Component"),
            position_(std::move(position)) {}

    PositionComponent::PositionComponent(std::string name) :
            Component(std::move(name)),
            position_(0, 0) {}

    PositionComponent::PositionComponent(std::string name, const unsigned x, const unsigned y) :
            Component(std::move(name)),
            position_(x, y) {}

    PositionComponent::PositionComponent(std::string name, std::pair<unsigned, unsigned> position) :
            Component(std::move(name)),
            position_(std::move(position)) {}

    std::pair<unsigned int, unsigned int> PositionComponent::get_position() const { return position_; }

    unsigned int PositionComponent::get_x() const { return position_.first; }

    unsigned int PositionComponent::get_y() const { return position_.second; }

    void PositionComponent::shift(const unsigned int x, const unsigned int y) {
        position_.first+=x;
        position_.second += y;
    }
}