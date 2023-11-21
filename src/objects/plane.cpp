#include "plane.h"

namespace objects {

void Plane::SetPrimitive(const sf::Sprite& circle) {
    plane_ = circle;
}

void Plane::SetToDraw(bool to_draw) {
    to_draw_ = to_draw;
}

void Plane::SetTargetPosition(const sf::Vector2f& target_position) {
    target_position_ = target_position;
}

void Plane::SetRotation(float angle) {
    plane_.rotate(angle);
}

sf::Sprite Plane::GetPrimitive() const {
    return plane_;
}

float Plane::GetSpeed() const {
    return speed_;
}

bool Plane::GetToDraw() const {
    return to_draw_;
}

sf::Vector2f Plane::GetTargetPosition() const {
    return target_position_;
}

sf::Vector2f Plane::GetCurrentPosition() const {
    return plane_.getPosition();
}

sf::Vector2f Plane::GetPlaneSize() const {
    return { plane_.getTexture()->getSize().x * plane_.getScale().x / 2,
             plane_.getTexture()->getSize().y * plane_.getScale().y / 2
           };
}

void Plane::Control() {
    sf::Vector2f direction;
    direction = target_position_ - plane_.getPosition();

    // Проверяем, не приблизились ли мы достаточно к цели, чтобы завершить перемещение
    if (std::sqrt(direction.x * direction.x + direction.y * direction.y) > speed_) {
        sf::Vector2f movement = speed_ * sf::Vector2f(direction.x / std::sqrt(direction.x * direction.x + direction.y * direction.y),
                                                      direction.y / std::sqrt(direction.x * direction.x + direction.y * direction.y)
                                                     );

        plane_.move(movement);
    }
}

} // namespace objects