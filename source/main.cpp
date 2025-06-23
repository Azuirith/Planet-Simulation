#include <iostream>
#include <math.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "RenderWindow.hpp"
#include "Planet.hpp"
#include "Sprite.hpp"

#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 900

#define FPS 1.f / 60.f

int main(int argc, char* argv[]) {
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Error: SDL_Init has failed. Error message: " << SDL_GetError() << std::endl;
    }

    if (!(IMG_Init(IMG_INIT_PNG))) {
        std::cout << "Error: IMG_Init has failed. Error message: " << SDL_GetError() << std::endl;
    }

    if (TTF_Init() < 0) {
        std::cout << "Error: TTF_Init has failed. Error message: " << SDL_GetError() << std::endl;
    }

    RenderWindow window("Planet Simulation", Vector(WINDOW_WIDTH, WINDOW_HEIGHT));

    float lastTime = 0.f, currentTime;
    float deltaTime = 0.f;

    bool gameRunning = true;

    Planet mars(Vector(0, WINDOW_HEIGHT / 2), 1000.f, 64.f);
    Sprite marsSprite = Sprite(Vector(0, 0), Vector(mars.GetRadius(), mars.GetRadius()) * 2);
    marsSprite.texture = window.LoadTexture("assets/planets/mars.png");
    mars.SetSprite(marsSprite);

    SDL_Event event;
    while (gameRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                gameRunning = false;
                break;
            }
        }

        currentTime = SDL_GetTicks();
        deltaTime += (currentTime - lastTime) / 1000;
        lastTime = currentTime;

        if (deltaTime >= FPS)
        {   
            window.Clear();

            mars.ApplyForce(Vector(1000.f, 0.f));
            mars.Update(deltaTime);
            window.Draw(mars.GetSprite(), false);

            window.Update();

            // TODO: Figure out how to properly do deltaTime like where it can overflow instead of getting
            // just set back to 0
            deltaTime = 0;
        }
    }

    SDL_Quit();
    return 0;
}