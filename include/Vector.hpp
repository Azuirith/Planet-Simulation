#pragma once

struct Vector {
    float x, y;

    Vector();
    Vector(float x, float y);

    Vector operator+(Vector other);
    void operator+=(Vector other);

    Vector operator-(Vector other);
    void operator-=(Vector other);
    
    Vector operator*(float multiplier);
    Vector operator/(float divisor);
};