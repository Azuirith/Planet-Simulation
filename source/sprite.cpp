#include "Sprite.hpp"
#include "Vector.hpp"

Sprite::Sprite() : position(Vector(0, 0)), size(Vector(0, 0)) {};

Sprite::Sprite(Vector position, Vector size) : position(position), size(size) {};