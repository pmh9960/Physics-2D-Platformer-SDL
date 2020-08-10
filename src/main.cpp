#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"
#include "Entity.hpp"

int main(int argc, char *args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "HEY... SDL INIT HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "HEY... IMG INIT HAS FAILED. IMG_ERROR: " << SDL_GetError() << std::endl;

    RenderWindow window("GAME v1.0", 1280, 720);

    SDL_Texture *grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");

    Entity entity0(100, 50, grassTexture);
    Entity entity1(50, 10, grassTexture);
    Entity entity2(26, 48, grassTexture);

    bool gameRunning = true;
    SDL_Event event;

    while (gameRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                gameRunning = false;
        }
        window.clear();
        window.render(entity0);
        window.render(entity1);
        window.render(entity2);
        window.display();
    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}