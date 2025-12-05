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

    inputManager = new InputManager();
    sdlEventManager = new SDLEventManager();
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
            if(map[y][x] > 1){
                WorldObject* tile = new WorldObject();
                //Uint8 a = (Uint8)((map[x][y] * 0.5f) * 255);
                tile->transform->SetPosition((float)(x * tilesize), (float)(y * tilesize));
                //tile->renderer->SetRenderColor({255, 255, 255, a});
                //tile->renderer->SetRenderCharacter((int)map[y][x]);
                renderManager->RendererAdd(tile);
                //SDL_SetRenderDrawColor(mainRenderer, 255, 255, 255, a);
                //SDL_FRect rect{(float)x,(float)y,1,1};
                //SDL_RenderRect(mainRenderer, &rect);
                //SDL_RenderDebugTextFormat(mainRenderer, tilesize*x - t->position.x, tilesize*y - t->position.y, "%i", (int)map[x][y]);
            }
        }
    }

    //Main loop
    while (!quit) {
        sdlEventManager->HandleSDLEvents();
        //inputManager->HandleInput();
        
        renderManager->Render();
    }
}