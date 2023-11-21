#pragma once

#include <cmath>
#include <SFML/Graphics.hpp>

namespace objects {

class Plane {
public:
    Plane() = default;

    void SetPrimitive(const sf::Sprite& circle);

    void SetToDraw(bool to_draw);

    void SetTargetPosition(const sf::Vector2f& target_position);

    void SetRotation(float angle);

    sf::Sprite GetPrimitive() const;

    float GetSpeed() const;

    bool GetToDraw() const;

    sf::Vector2f GetTargetPosition() const;

    sf::Vector2f GetCurrentPosition() const;

    sf::Vector2f GetPlaneSize() const;

    void Control();

private:
    sf::Sprite plane_;
    float speed_ = 0.02f;
    bool to_draw_ = true;
    sf::Vector2f target_position_ = {0.f, 0.f};
};

} // namespace objects