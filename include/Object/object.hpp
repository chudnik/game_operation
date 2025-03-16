/**
 * @file object.hpp
 * @brief Defines the Object class, which represents an entity that can hold multiple components.
 */

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Components/component.hpp"
#include <vector>
#include <memory>
#include <algorithm>

namespace object {
    /**
     * @class Object
     * @brief Represents an object that can hold multiple components.
     *
     * The Object class is a container for components. It allows adding, retrieving,
     * and removing components of different types. Components are stored as unique pointers
     * to ensure proper memory management.
     */
    class Object {
    public:
        /**
         * @brief Default constructor.
         */
        Object() = default;

        /**
         * @brief Adds a component of the specified type to the object.
         *
         * This method creates a new component of type `T` and adds it to the object's
         * component list. The component is constructed using the provided arguments.
         *
         * @tparam T The type of the component to add. Must inherit from `components::Component`.
         * @tparam Args Variadic template for the constructor arguments of the component.
         * @param args Arguments to forward to the constructor of the component.
         */
        template<typename T, typename ... Args>
        void add_component(Args &&...args) {
            components_.push_back(std::make_unique<T>(std::forward<Args>(args)...));
        }

        /**
         * @brief Retrieves a component of the specified type.
         *
         * This method searches for a component of type `T` in the object's component list.
         * If found, it returns a raw pointer to the component; otherwise, it returns `nullptr`.
         *
         * @tparam T The type of the component to retrieve. Must inherit from `components::Component`.
         * @return A pointer to the component of type `T`, or `nullptr` if not found.
         */
        template<typename T>
        T *get_component() {
            for (const auto &component: components_) {
                if (auto ptr = dynamic_cast<T *>(component.get()))
                    return ptr;
            }
            return nullptr;
        }

        /**
         * @brief Removes all components of the specified type.
         *
         * This method removes all components of type `T` from the object's component list.
         * It uses `std::remove_if` to filter out the components and `erase` to remove them.
         *
         * @tparam T The type of the component to remove. Must inherit from `components::Component`.
         */
        template<typename T>
        void remove_component() {
            auto it = std::remove_if(
                    components_.begin(), components_.end(),
                    [](const std::unique_ptr<components::Component> &component) {
                        return dynamic_cast<T *>(component.get()) !=
                               nullptr;
                    });
            components_.erase(it, components_.end());
        }

    private:
        std::vector<std::unique_ptr<components::Component>> components_; ///< List of components owned by the object.
    };
}

#endif