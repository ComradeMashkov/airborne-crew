#include "plane.h"

namespace objects {
  /*  namespace global_parameters{
        extern float MAP_TOP_COORDINATES;
        extern float MAP_LEFT_COORDINATES;
        extern float MAP_WIDTH;
        extern float MAP_HEIGHT;
    }*/

void Plane::SetPrimitive(const sf::Sprite& circle) {
    plane_ = circle;
}

void Plane::SetToDraw(bool to_draw) {
    to_draw_ = to_draw;
}

void Plane::SetTargetPosition(const sf::Vector2f& target_position) {
    target_position_ = target_position;
    tracking_target = true;
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
    if (to_draw_){
        coordinates = "(" + std::to_string(plane_.getPosition().x/480*0.61268+-77.347776) +";" + std::to_string(plane_.getPosition().y/360*-0.36113+39.089530) + ")";
        sf::Vector2f direction;
    if (this->tracking_target){
        direction = target_position_ - plane_.getPosition();
        if (direction.x > 0)target_angle = asin(direction.y/sqrt(pow(direction.x,2)+pow(direction.y,2)));
        else target_angle = M_PI-asin(direction.y/sqrt(pow(direction.x,2)+pow(direction.y,2)));
    }

    // Проверяем, не приблизились ли мы достаточно к цели, чтобы завершить перемещение
    //if (std::sqrt(direction.x * direction.x + direction.y * direction.y) < 10*speed_) this->tracking_target = false;
        if(target_angle - angle > 2*M_PI) angle += 2*M_PI;
        if(angle - target_angle > 2*M_PI) angle -= 2*M_PI;
        if (angle - target_angle > 0.02f || angle - target_angle < -0.02f){
            if((target_angle - angle > 0 && target_angle - angle < M_PI) || (target_angle - angle < -M_PI )) angle += angle_speed;
            else angle -= angle_speed;
        }
        else tracking_target = false;
        

        sf::Vector2f movement = speed_ * sf::Vector2f(cos(angle),sin(angle));

        plane_.move(movement);
        plane_.setRotation(angle/M_PI*180+90);
    }
}

} // namespace objects