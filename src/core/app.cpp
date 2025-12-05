#include "app.h"
#include "../level/level_generator.h"
#include "../rendering/camera.h"
#include "../components/world_object.h"
#include "../util/common.h"
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

    WorldObject player;
    player.renderer->SetRenderCharacter('@');
    player.renderer->SetRenderColor({255, 182, 193, 255});
    renderManager->RendererAdd(&player);
    cam.SetFollowTarget(&player);
    Transform* t = player.transform;

    LevelGenerator gen;
    std::vector<std::vector<float>> map = gen.GenerateLevel(400, 400);

    for(int x = 0; x < 400; x++){
        for(int y = 0; y < 400; y++){
            if(map[y][x] > 0){
                WorldObject* tile = new WorldObject();
                tile->transform->SetPosition((float)(x * tilesize), (float)(y * tilesize));
                renderManager->RendererAdd(tile);
                //int a = (int)((map[x][y] * 0.5f) * 255);
                //SDL_SetRenderDrawColor(mainRenderer, 255, 255, 255, a);
                //SDL_FRect rect{(float)x,(float)y,1,1};
                //SDL_RenderRect(mainRenderer, &rect);
                //SDL_RenderDebugTextFormat(mainRenderer, tilesize*x - t->position.x, tilesize*y - t->position.y, "%i", (int)map[x][y]);
            }
            //SDL_RenderDebugTextFormat(mainRenderer, tilesize*x, tilesize*y, "%i", TestNoise(x, y));
        }
    }

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
                    t->SetPosition(t->position.x, t->position.y - tilesize);
                }
                if(e.key.key == SDLK_DOWN){
                    t->SetPosition(t->position.x, t->position.y + tilesize);
                }
                if(e.key.key == SDLK_RIGHT){
                    t->SetPosition(t->position.x + tilesize, t->position.y);
                }
                if(e.key.key == SDLK_LEFT){
                    t->SetPosition(t->position.x - tilesize, t->position.y);
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

        //if(!paused) seed++;

        renderManager->Render();
    }
}