#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "RenderWindow.hpp"
#include "Sprite.hpp"
#include "Vector.hpp"

#define WINDOW_COLOR_R 0
#define WINDOW_COLOR_G 0
#define WINDOW_COLOR_B 0
#define WINDOW_COLOR_A 255

#define TEXTURE_RESOLUTION 128

RenderWindow::RenderWindow(const char* title, Vector size) {
    window = SDL_CreateWindow(title, 
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                              size.x, size.y,
                              0);

    if (window == nullptr) {
        std::cout << "Error: Window has failed to init. Error message: " << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == nullptr) {
        std::cout << "Error: Renderer has failed to init. Error message: " << SDL_GetError() << std::endl;
    }

    SDL_SetRenderDrawColor(renderer, WINDOW_COLOR_R, WINDOW_COLOR_G, WINDOW_COLOR_B, WINDOW_COLOR_A);
}

SDL_Texture* RenderWindow::LoadTexture(const char* filePath) {
    SDL_Texture* texture;
    texture = IMG_LoadTexture(renderer, filePath);

    if (texture == nullptr) {
        std::cout << "Error: LoadTexture has failed. Error message: " << SDL_GetError() << std::endl;
    }

    return texture;
}

void RenderWindow::Clear() {
    SDL_RenderClear(renderer);
}

void RenderWindow::Draw(Sprite& sprite, bool isText) {
    SDL_Rect destination;
    destination.x = sprite.position.x;
    destination.y = sprite.position.y;
    destination.w = sprite.size.x;
    destination.h = sprite.size.y; 

    // Done because text does not have the same resoultion as other sprites
    if (isText)
    {
        SDL_RenderCopy(renderer, sprite.texture, nullptr, &destination);
        return;
    }
    
    SDL_Rect source;
    source.x = 0;
    source.y = 0;
    source.w = TEXTURE_RESOLUTION;
    source.h = TEXTURE_RESOLUTION;

    SDL_RenderCopy(renderer, sprite.texture, &source, &destination);
}

void RenderWindow::Update() {
    SDL_RenderPresent(renderer);
}