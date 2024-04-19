#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity
{
public:
    Entity(float p_x, float p_y, SDL_Texture *p_text);
    float getX() { return x; }
    float getY() { return y; }
    SDL_Texture *getText() { return text; }
    SDL_Rect getCurrentFrame() { return currentFrame; }

private:
    float x, y;
    SDL_Rect currentFrame;
    SDL_Texture *text;
};