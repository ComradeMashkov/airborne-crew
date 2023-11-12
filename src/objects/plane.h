#pragma once

#include <cmath>
#include <SFML/Graphics.hpp>

namespace objects {

const sf::Vector2f CIRCLE_SIZE = { 50.f, 50.f };

class Plane {
public:
    Plane() = default;

    void SetPrimitive(const sf::CircleShape& circle);

    void SetToDraw(bool to_draw);

    void SetTargetPosition(const sf::Vector2f& target_position);

    sf::CircleShape GetPrimitive() const;

    float GetSpeed() const;

    bool GetToDraw() const;

    sf::Vector2f GetTargetPosition() const;

    void Control();

private:
    sf::CircleShape plane_;
    float speed_ = 0.05f;
    bool to_draw_ = true;
    sf::Vector2f target_position_ = {0.f, 0.f};
};

} // namespace objects