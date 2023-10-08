#include <SDL2/SDL.h>
#include <random>
#include <iostream>
#include <stdio.h>


int main() {

    SDL_Window* window = nullptr;
    SDL_Renderer* render = nullptr;
    
    SDL_CreateWindowAndRenderer(40 * 20, 40 * 20, 0, &window, &render);
    SDL_RenderSetScale(render, 20, 20);

    int x = 25;
    int y = 25;

    std:: random_device dev;
    std:: uniform_int_distribution<uint8_t> nd(0, 4);

    while(true) {
        uint8_t dir = nd(dev);

        SDL_Event e;
    while (SDL_PollEvent(&e)) 
    {
        if(e.type == SDL_QUIT)
        {
            break;
        }
        // Handle events
    }
        switch(dir)
        {
            case 0:
            x -= 1;
            y -= 1;
            break;

            case 1:
            x += 1;
            y -= 1;
            break;

            case 2:
            
            x += 1;
            y += 1;
            break;

            case 3:
            x -= 1;
            y += 1;
            break;

        }
        uint8_t m = 60;
        uint8_t total = 255;
        SDL_SetRenderDrawColor(render, m * dir % total, m * dir % total, m * dir % total, m * dir % total);
        SDL_RenderDrawPoint(render, x, y);
        SDL_RenderPresent(render);


        if (x > 50 || x < 0 || y > 50 || y < 0) 
        {
            x = 25;
            y = 25;
        }
        SDL_Delay(50);
    }



}


