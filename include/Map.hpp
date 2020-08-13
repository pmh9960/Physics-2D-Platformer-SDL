#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Map.hpp"
#include "Math.hpp"

class Map
{
public:
    enum TexType
    {
        TypeNone,
        TypeDirt,
        TypeGrass,
        TypeWater
    };
    Map(RenderWindow *window);
    ~Map();

    void LoadMap();
    void DrawMap() const;

private:
    RenderWindow *m_Window;

    SDL_Texture *m_Dirt;
    SDL_Texture *m_Grass;
    SDL_Texture *m_Water;

    int m_Map[20][25];
};