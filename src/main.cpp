#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Map.hpp"

int main(int argc, char *args[])
{
    // Limiting Frame Rate
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;

    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "HEY... SDL INIT HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "HEY... IMG INIT HAS FAILED. IMG_ERROR: " << SDL_GetError() << std::endl;

    RenderWindow window("GAME v1.0", 800, 640); // 32-pixel = 1 block
                                                // 25 X 20

    SDL_Texture *grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");
    std::vector<Entity> entities = {Entity(Vector2f(30, 0), grassTexture),
                                    Entity(Vector2f(10, 20), grassTexture),
                                    Entity(Vector2f(50, 20), grassTexture)};
    {
        Entity wilson(Vector2f(100, 20), grassTexture);
        entities.push_back(wilson);
    }

    SDL_Texture *zolamenTexture = window.loadTexture("res/gfx/zolamen.png");
    SDL_Texture *redZolamenTexture = window.loadTexture("res/gfx/zolamen_red.png");
    std::vector<Entity> zolamens{Entity(Vector2f(50, 50), zolamenTexture),
                                 Entity(Vector2f(82, 50), redZolamenTexture)};

    bool gameRunning = true;
    SDL_Event event;

    Map map(&window);

    while (gameRunning)
    {
        // Measure cycle time
        frameStart = SDL_GetTicks();

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                gameRunning = false;
        }
        window.clear();
        map.DrawMap();
        for (Entity &e : entities)
        {
            window.render(e);
        }
        for (Entity &z : zolamens)
        {
            window.render(z);
        }
        window.display();

        // Move 1 pixel at every frame.
        zolamens[0].Move(1, 1);
        zolamens[1].Move(1, 1);

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}