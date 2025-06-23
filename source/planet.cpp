#include <iostream>

#include "Planet.hpp"

Planet::Planet(Vector position, float mass, float radius) : position(position), 
                                                            mass(mass),
                                                            radius(radius) {};

void Planet::Update(float deltaTime) {
    velocity += acceleration * deltaTime;
    position += velocity * deltaTime;
    sprite.position = position - Vector(radius, radius);
}

void Planet::ApplyForce(Vector force) {
    Vector deltaAcceleration = force / mass;
    acceleration += deltaAcceleration;
    std::cout << deltaAcceleration.x << ", " << deltaAcceleration.y << std::endl;
}

Vector Planet::GetPosition() {
    return position;
}

float Planet::GetRadius() {
    return radius;
}

Sprite& Planet::GetSprite() {
    return sprite;
}

void Planet::SetSprite(Sprite& sprite) {
    this->sprite = sprite;
}