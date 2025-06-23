#pragma once

#include "Vector.hpp"
#include "Sprite.hpp"

class Planet {
  public: 
    Planet(Vector position, float mass, float radius);

    void Update(float deltaTime);
    void ApplyForce(Vector force);

    Vector GetPosition();
    float GetRadius();
    Sprite& GetSprite();

    void SetSprite(Sprite& sprite);
  private:
    Vector position;
    Vector velocity;
    Vector acceleration;
    Vector netForce;

    float mass;
    float radius;

    Sprite sprite;
};