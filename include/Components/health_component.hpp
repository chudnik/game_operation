#include "component.hpp"

namespace components {
    class HealthComponent : public Component {
    public:
        HealthComponent();

        explicit HealthComponent(std::string name);

        explicit HealthComponent(double max_health);

        HealthComponent(double current_health, double max_health);

        HealthComponent(std::string name, double max_health);

        HealthComponent(std::string name, double current_health, double max_health);

        [[nodiscard]] double get_current_health() const;

        [[nodiscard]] double get_max_health() const;

        void take_damage(double health_point);

        void heal(double health_point);

    private:
        double current_health_;
        double max_health_;
    };
}