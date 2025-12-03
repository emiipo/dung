#include "app.h"
#include "../level/level_generator.h"
#include "../camera/camera.h"
#include "../components/transform.h"
#include <iostream>

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
        mainWindow = nullptr;
        SDL_Quit();
        return;
    }
}

Application::~Application() {
    SDL_DestroyRenderer(mainRenderer);
    mainRenderer = nullptr;
    SDL_DestroyWindow(mainWindow);
    mainWindow = nullptr;
    SDL_Quit();
}

void Application::Run(){
    //Final exit code
    int exitCode{ 0 };

    bool quit = false;
    bool paused = true;
    SDL_Event e;
    SDL_zero(e);

    SDL_SetRenderDrawBlendMode(mainRenderer, SDL_BLENDMODE_BLEND);

    Camera cam(0,0,640,480);
    cam.AddComponent<Transform>();
    cam.AddComponent<Transform>();
    cam.AddComponent<Transform>();
    cam.AddComponent<Transform>();

    Transform* t = cam.GetComponent<Transform>();
    t->TestComp();

    LevelGenerator gen;
    const int tilesize = SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE;
    std::vector<std::vector<float>> map = gen.GenerateLevel(20, 20);

    //Main loop
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
            else if(e.type == SDL_EVENT_KEY_DOWN){
                if(e.key.key == SDLK_SPACE){
                    paused = !paused;
                }
            }
            else if(e.type == SDL_EVENT_MOUSE_WHEEL){
                if(e.wheel.y > 0){
                    //size++;
                }
                else{
                    //size--;
                }
            }
        }

        SDL_SetRenderDrawColor(mainRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE); // Set render draw color to black
        SDL_RenderClear(mainRenderer); // Clear the renderer

        SDL_SetRenderDrawColor(mainRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);  /* white, full alpha */
        for(int x = 0; x < 20; x++){
            for(int y = 0; y < 20; y++){
                //if(map[y][x] > 0){
                    int a = (int)((map[x][y] * 0.5f) * 255);
                    SDL_SetRenderDrawColor(mainRenderer, 255, 255, 255, a);
                    //SDL_FRect rect{(float)x,(float)y,1,1};
                    //SDL_RenderRect(mainRenderer, &rect);
                    SDL_RenderDebugTextFormat(mainRenderer, tilesize*x, tilesize*y, "%i", (int)map[x][y]);
                //}
                //SDL_RenderDebugTextFormat(mainRenderer, tilesize*x, tilesize*y, "%i", TestNoise(x, y));
            }
        }

        //if(!paused) seed++;
        
        SDL_RenderPresent(mainRenderer); // Render the screen
    }
}