#include "../include/Entity.h"

Entity::Entity(float p_x, float p_y, SDL_Texture *p_text)
    : x(p_x), y(p_y), text(p_text)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 100;
    currentFrame.h = 100;
}
