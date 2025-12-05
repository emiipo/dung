#include "render_manager.h"
#include "../util/common.h"

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
            RenderEntity(entity);
        }
    }

    // For now doing every frame but look into a better way later
    mainCamera->Update();

    SDL_RenderPresent(mainRenderer); // Render the screen
}

void RenderManager::RenderEntity(WorldObject* entity){
    // For now only rendering ascii, later implement different rendering based on renderer type
    if(entity->transform == nullptr || entity->renderer == nullptr) return;
    SDL_SetRenderDrawColor(mainRenderer, entity->renderer->GetRenderColor().r, entity->renderer->GetRenderColor().g, entity->renderer->GetRenderColor().b, entity->renderer->GetRenderColor().a);
    SDL_RenderDebugTextFormat(mainRenderer, entity->transform->position.x - mainCamera->transform->position.x, entity->transform->position.y - mainCamera->transform->position.y, "%c", entity->renderer->GetRenderCharacter());
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