#pragma once

#include "Sprite.hpp"

class RenderWindow {
  public: 
    RenderWindow(const char* title, Vector size);

    SDL_Texture* LoadTexture(const char* filePath);

    void Clear();
    void Draw(Sprite& sprite, bool isText);
    void Update();
  private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};