#include "render_manager.h"

RenderManager::RenderManager(SDL_Window* mainWindow){
    mainRenderer = SDL_CreateRenderer(mainWindow, NULL);
    if (mainRenderer == nullptr) {
        SDL_Log("SSDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(mainWindow);
        mainWindow = nullptr;
        SDL_Quit();
        return;
    }

    SDL_SetRenderDrawBlendMode(mainRenderer, SDL_BLENDMODE_BLEND);
}

RenderManager::~RenderManager(){
    SDL_DestroyRenderer(mainRenderer);
    mainRenderer = nullptr;
}

void RenderManager::Render(){
    SDL_SetRenderDrawColor(mainRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE); // Set render draw color to black
    SDL_RenderClear(mainRenderer); // Clear the renderer

    SDL_SetRenderDrawColor(mainRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);  /* white, full alpha */
    if(mainCamera != nullptr){
        for(WorldObject* entity : mEntitiesToRender){
            entity->Render(mainCamera->transform->position.x, mainCamera->transform->position.y);
        }
    }

    SDL_RenderPresent(mainRenderer); // Render the screen
}

void RenderManager::SetMainCamera(Camera* camera){
    mainCamera = camera;
}

void RenderManager::RendererAdd(WorldObject* obj){
    mEntitiesToRender.push_back(obj);
}

void RenderManager::RendererRemove(WorldObject* obj){
    mEntitiesToRender.remove(obj);
}