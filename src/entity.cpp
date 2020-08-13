#include "Entity.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Entity::Entity(Vector2f p_pos, SDL_Texture *p_tex)
    : pos(p_pos), tex(p_tex)
// Member initialization list
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;
}

Vector2f &Entity::getPos()
{
    return pos;
}

SDL_Texture *Entity::getTex()
{
    return tex;
}

SDL_Rect Entity::getCurrentFrame()
{
    return currentFrame;
}

void Entity::Move(int xa, int ya)
{
    pos.x += xa;
    pos.y += ya;
}