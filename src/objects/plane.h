#pragma once

#include <cmath>
#include <SFML/Graphics.hpp>

namespace objects {

const sf::Vector2f CIRCLE_SIZE = { 25.f, 25.f };

class Plane {
public:
    Plane() = default;

    void SetPrimitive(const sf::RectangleShape& square);

    void SetToDraw(bool to_draw);

    void SetTargetPosition(const sf::Vector2f& target_position);

    sf::RectangleShape GetPrimitive() const;

    float GetSpeed() const;

    bool GetToDraw() const;

    sf::Vector2f GetTargetPosition() const;

    void Control();

private:
    sf::RectangleShape plane_;
    float speed_ = 0.05f;
    bool to_draw_ = true;
    sf::Vector2f target_position_ = {0.f, 0.f};
};

} // namespace objects