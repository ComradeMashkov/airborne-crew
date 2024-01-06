#include "plane.h"

namespace objects {

void Plane::SetPrimitive(const sf::Sprite& circle) {
    plane_ = circle;
}

void Plane::SetToDraw(bool to_draw) {
    to_draw_ = to_draw;
    longtitude = "0°";
    latitude = "0°";
}

void Plane::SetTargetPosition(const sf::Vector2f& target_position) {
    target_position_ = target_position;
    tracking_target_ = true;
}

void Plane::SetAngle(float angle) {
    angle_ = angle;
}

void Plane::SetLinearSpeed(float linear_speed) {
    speed_ = linear_speed;
}

void Plane::SetAngleSpeed(float angle_speed) {
    angle_speed_ = angle_speed;
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
    if (to_draw_) {
        double lng = plane_.getPosition().y / global_parameters::PLANE_ANGLE_ROTATION_Y * global_parameters::PLANE_ROTATION_COEFFICIENT_Y + global_parameters::PLANE_INITIAL_ANGLE_POS_Y;
        double lat = plane_.getPosition().x / global_parameters::PLANE_ANGLE_ROTATION_X * global_parameters::PLANE_ROTATION_COEFFICIENT_X + global_parameters::PLANE_INITIAL_ANGLE_POS_X;
        
        longtitude = std::to_string(lng) + "°";
        latitude = std::to_string(lat) + "°";

        sf::Vector2f direction;

        if (tracking_target_) {
            direction = target_position_ - plane_.getPosition();
            if (direction.x > 0) {
                target_angle_ = asin(direction.y / sqrt(pow(direction.x, 2) + pow(direction.y, 2)));
            }
            else {
                target_angle_ = M_PI - asin(direction.y / sqrt(pow(direction.x, 2) + pow(direction.y, 2)));
            }
        }

        if (target_angle_ - angle_ > 2 * M_PI) {
            angle_ += 2 * M_PI;
        }

        if (angle_ - target_angle_ > 2 * M_PI) {
            angle_ -= 2 * M_PI;
        }

        if (angle_ - target_angle_ > global_parameters::PLANE_CRITICAL_ANGLE || angle_ - target_angle_ < -global_parameters::PLANE_CRITICAL_ANGLE){
            if ((target_angle_ - angle_ > 0 && target_angle_ - angle_ < M_PI) || (target_angle_ - angle_ < -M_PI )) {
                angle_ += angle_speed_;
            }
            else {
                angle_ -= angle_speed_;
            }
        }
        else {
            tracking_target_ = false;
        }

        sf::Vector2f movement = speed_ * sf::Vector2f(cos(angle_), sin(angle_));

        plane_.move(movement);
        plane_.setRotation(angle_ / M_PI * 180 + 90);
    }
}

std::string Plane::FloatToStringWithPrecision(float number, int precision) {
    std::string result = std::to_string(number);
    const size_t DOT = result.find('.');
    
    if (DOT != std::string::npos) {
        size_t end_position = DOT + 1 + precision;
        if (end_position < result.length()) {
            result.erase(result.begin() + end_position, result.end());
        }
    }

    return result;
}

} // namespace objects