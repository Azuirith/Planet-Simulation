#include "Vector.hpp"

Vector::Vector() : x(0), y(0) {};

Vector::Vector(float x, float y) : x(x), y(y) {};

Vector Vector::operator+(Vector other) {
    Vector result;
    result.x = this->x + other.x;
    result.y = this->y + other.y;
    return result;
}

void Vector::operator+=(Vector other) {
    this->x += other.x;
    this->y += other.y;
}

Vector Vector::operator-(Vector other) {
    Vector result;
    result.x = this->x - other.x;
    result.y = this->y - other.y;
    return result;
}

void Vector::operator-=(Vector other) {
    this->x -= other.x;
    this->y -= other.y;
}
    
Vector Vector::operator*(float multiplier) {
    Vector result;
    result.x = this->x * multiplier;
    result.y = this->y * multiplier;
    return result;
}

Vector Vector::operator/(float divisor) {
    Vector result;
    result.x = this->x / divisor;
    result.y = this->y / divisor;
    return result;
}