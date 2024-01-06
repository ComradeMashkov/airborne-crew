#pragma once

#include "../global_parameters.h"

#include <cmath>
#include <SFML/Graphics.hpp>

namespace objects {

const sf::Vector2f PLANE_SIZE = { 50.f, 50.f };

class Plane {
public:
    Plane() = default;

    void SetPrimitive(const sf::Sprite& circle);

    void SetToDraw(bool to_draw);

    void SetTargetPosition(const sf::Vector2f& target_position);

    void SetAngle(float angle);

    void SetLinearSpeed(float linear_speed);

    void SetAngleSpeed(float angle_speed);

    sf::Sprite GetPrimitive() const;

    float GetSpeed() const;

    bool GetToDraw() const;

    sf::Vector2f GetTargetPosition() const;

    sf::Vector2f GetCurrentPosition() const;

    sf::Vector2f GetPlaneSize() const;

    void Control();

    static std::string FloatToStringWithPrecision(float number, int precision = 2);

public:
    std::string longtitude = "0°";
    std::string latitude = "0°";

private:
    float angle_speed_ = 0.01f;
    float angle_ = 0.f;
    float target_angle_ = 0.f;
    bool tracking_target_ = false;
    sf::Sprite plane_;
    float speed_ = 0.5f;
    bool to_draw_ = false;
    sf::Vector2f target_position_ = { 0.f, 0.f };
};

} // namespace objects