#include "render_manager.h"
#include "../util/common.h"
#include "../components/renderer.h"

RenderManager::RenderManager(SDL_Window* mainWindow, bool renderDebug){
    mainRenderer = SDL_CreateRenderer(mainWindow, NULL);
    //mainRenderer = SDL_CreateGPURenderer(NULL, mainWindow);
    if (mainRenderer == nullptr) {
        SDL_Log("SSDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(mainWindow);
        mainWindow = nullptr;
        SDL_Quit();
        return;
    }

    SDL_SetRenderDrawBlendMode(mainRenderer, SDL_BLENDMODE_BLEND);

    this->renderDebug = renderDebug;
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
            if(CheckOverlap(entity->renderer)){
                RenderEntity(entity);
                if(renderDebug) RenderDebug(entity);
            }
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

void RenderManager::RenderDebug(WorldObject* entity){
    Collider* col = entity->collider;
    SDL_FRect debugRect;
    if(col != nullptr){
        Vector4 bounds = col->GetBounds();
        debugRect = {bounds.x - mainCamera->transform->position.x, bounds.y - mainCamera->transform->position.y, debugRect.w = bounds.z, debugRect.h = bounds.w};
        SDL_SetRenderDrawColor(mainRenderer, 0, 255, 0, 255);
        SDL_RenderRect(mainRenderer, &debugRect);
    }
}

// This will be same code as collision checking, yet keeping seperate for now as I would have to put it in common or include collisions
// into this(which might be the go). For now just using the camera for first arg
bool RenderManager::CheckOverlap(Renderer* renderer){
    // Only grabbing camera bounds here as it might change, later on camera change just change gen obj or smth
    Vector4 cameraBounds = mainCamera->GetBounds();
    Vector4 rendererBounds = renderer->GetBounds();
    return (cameraBounds.x + cameraBounds.z >= rendererBounds.x && rendererBounds.x + rendererBounds.z >= cameraBounds.x) && (cameraBounds.y + cameraBounds.w >= rendererBounds.y && rendererBounds.y + rendererBounds.w >= cameraBounds.y);
}

void RenderManager::SetMainCamera(Camera* camera){
    mainCamera = camera;
}

// TODO: make sure it has renderer
void RenderManager::RendererAdd(WorldObject* obj){
    mEntitiesToRender.push_back(obj);
}

void RenderManager::RendererRemove(WorldObject* obj){
    mEntitiesToRender.remove(obj);
}