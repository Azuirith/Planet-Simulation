#pragma once 

#include <SDL2/SDL.h>

#include "Vector.hpp"

struct Sprite {
    Sprite();
    Sprite(Vector position, Vector size);

    SDL_Texture* texture;

    Vector position;
    Vector size;
};