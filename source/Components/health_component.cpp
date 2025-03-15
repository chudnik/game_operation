#include "Components/health_component.hpp"

namespace components {
    HealthComponent::HealthComponent() :
            Component("Health-Component"),
            current_health_(100),
            max_health_(100) {}

    HealthComponent::HealthComponent(std::string name) :
            Component(std::move(name)),
            current_health_(100),
            max_health_(100) {}

    HealthComponent::HealthComponent(const double max_health) :
            Component("Health-Component"),
            current_health_(max_health),
            max_health_(max_health) {}

    HealthComponent::HealthComponent(std::string name, const double max_health) :
            Component(std::move(name)),
            current_health_(max_health),
            max_health_(max_health) {}

    HealthComponent::HealthComponent(const double current_health, const double max_health) :
            Component("Health-Component"),
            current_health_(current_health),
            max_health_(max_health) {}

    HealthComponent::HealthComponent(std::string name, const double current_health, const double max_health) :
            Component(std::move(name)),
            current_health_(current_health),
            max_health_(max_health) {}

    double HealthComponent::get_current_health() const { return current_health_; }

    double HealthComponent::get_max_health() const { return max_health_; }

    void HealthComponent::heal(const double health_point) {
        current_health_ += health_point;
        if (current_health_ > max_health_) {
            current_health_ = max_health_;
        }
    }

    void HealthComponent::take_damage(const double health_point) {
        current_health_ -= health_point;
        if (current_health_ < 0) {
            current_health_ = 0;
        }
    }
}