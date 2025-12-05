#include "app.h"
#include "../level/level_generator.h"
#include "../rendering/camera.h"
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

    renderManager = new RenderManager(mainWindow);
}

Application::~Application() {
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

    Camera cam(0,0,640,480);
    renderManager->SetMainCamera(&cam);

    Transform* t = cam.GetComponent<Transform>();

    LevelGenerator gen;
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
                if(e.key.key == SDLK_UP){
                    t->SetPosition(t->position.x, t->position.y - 1);
                }
                if(e.key.key == SDLK_DOWN){
                    t->SetPosition(t->position.x, t->position.y + 1);
                }
                if(e.key.key == SDLK_RIGHT){
                    t->SetPosition(t->position.x + 1, t->position.y);
                }
                if(e.key.key == SDLK_LEFT){
                    t->SetPosition(t->position.x - 1, t->position.y);
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

        /*for(int x = 0; x < 20; x++){
            for(int y = 0; y < 20; y++){
                //if(map[y][x] > 0){
                    int a = (int)((map[x][y] * 0.5f) * 255);
                    //SDL_SetRenderDrawColor(mainRenderer, 255, 255, 255, a);
                    //SDL_FRect rect{(float)x,(float)y,1,1};
                    //SDL_RenderRect(mainRenderer, &rect);
                    //SDL_RenderDebugTextFormat(mainRenderer, tilesize*x - t->position.x, tilesize*y - t->position.y, "%i", (int)map[x][y]);
                //}
                //SDL_RenderDebugTextFormat(mainRenderer, tilesize*x, tilesize*y, "%i", TestNoise(x, y));
            }
        }*/

        //if(!paused) seed++;

        renderManager->Render();
    }
}