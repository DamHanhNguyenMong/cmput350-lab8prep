#pragma once

#include "vector_util.h"
#include <SFML/System/Vector2.hpp>

struct BasicTransform {
    // methods...

    // Constructor
    BasicTransform(
        const sf::Vector2f& scale = sf::Vector2f(1.f, 1.f), // keep the origin size
        const sf::Vector2f& translation = sf::Vector2f(0.f, 0.f) // don't move the vector
    )
        : scale(scale), translation(translation) {}

    sf::Vector2f applyPoint(const sf::Vector2f& p) const{
        // applyPoint(p) = p*scale + point
        return {
            p.x * scale.x + translation.x,
            p.y * scale.y + translation.y
        };
    }

    sf::Vector2f applyVector(const sf::Vector2f& p) const {
        // Scale but dont translate
        return {
            p.x * scale.x,
            p.y * scale.y
        };
    }

    bool operator==(const BasicTransform& other) const {
        // If both their scale and translation are exactly equal. the transforms are equal
        return scale == other.scale && translation == other.translation;
    }

    sf::Vector2f scale;
    sf::Vector2f translation;
};
