#include "app.h"
#include <iostream>

//Setting screen dimensions
kScreenWidth{ 640 };
kScreenHeight{ 480 };

Application::Application() {
    SDL_Init(SDL_INIT_VIDEO);

    mainWindow = SDL_CreateWindow("dung", kScreenWidth, kScreenHeight, 0);
    if (mainWindow == nullptr) {
        SDL_Log("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return;
    }

    mainRenderer = SDL_CreateRenderer(mainWindow, NULL);
    if (mainRenderer == nullptr) {
        SDL_Log("SSDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(mainWindow);
        SDL_Quit();
        return;
    }
}

Application::~Application() {
    SDL_DestroyRenderer(mainRenderer);
    SDL_DestroyWindow(mainWindow);
    SDL_Quit();
}

void Application::Run(){
    SDL_Event e;
    bool quit = false;

    // Define a rectangle
    SDL_FRect greenSquare {270, 190, 100, 100};

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(mainRenderer, 0, 0, 0, 255); // Set render draw color to black
        SDL_RenderClear(mainRenderer); // Clear the renderer

        SDL_SetRenderDrawColor(mainRenderer, 0, 255, 192, 203); // Set render draw color to green
        SDL_RenderFillRect(mainRenderer, &greenSquare); // Render the rectangle
        
        SDL_RenderPresent(mainRenderer); // Render the screen
    }
}