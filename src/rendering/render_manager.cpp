#include <algorithm>
#include <SDL3/SDL_render.h>
#include "render_manager.h"
#include "camera.h"
#include "../components/renderer.h"
#include "../components/collider.h"

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
        // Im pretty sure we only need to grab it once per render call
        cameraBounds = mainCamera->GetBounds();
        for(Renderer* renderer : mRenderers){
            if(renderer == nullptr) continue;
            rendererBounds = renderer->GetBounds();
            if(CheckOverlap(renderer)){
                RenderEntity(renderer);
                //Super dumb way of getting it, might be smart for the renderer to have a pointer to the collider, but this is only for debug
                if(renderDebug) RenderDebug(renderer->gameObject->GetComponent<Collider>());
            }
        }
    }

    // For now doing every frame but look into a better way later
    mainCamera->Update();

    SDL_RenderPresent(mainRenderer); // Render the screen
}

void RenderManager::RenderEntity(Renderer* renderer){
    // For now only rendering ascii, later implement different rendering based on renderer type
    SDL_Color color = renderer->GetRenderColor();
    SDL_SetRenderDrawColor(mainRenderer, color.r, color.g, color.b, color.a);
    SDL_RenderDebugTextFormat(mainRenderer, rendererBounds.x - cameraBounds.x, rendererBounds.y - cameraBounds.y, "%c", renderer->GetRenderCharacter());
}

void RenderManager::RenderDebug(Collider* collider){
    if(collider != nullptr){
        Vector4 colliderBounds = collider->GetBounds();
        debugRect = {colliderBounds.x - cameraBounds.x, colliderBounds.y - cameraBounds.y, colliderBounds.z, colliderBounds.w};
        SDL_SetRenderDrawColor(mainRenderer, 0, 255, 0, 255);
        SDL_RenderRect(mainRenderer, &debugRect);
    }
}

// This will be same code as collision checking, yet keeping seperate for now as I would have to put it in common or include collisions
// into this(which might be the go). For now just using the camera for first arg
bool RenderManager::CheckOverlap(Renderer* renderer){
    return (cameraBounds.x + cameraBounds.z >= rendererBounds.x && rendererBounds.x + rendererBounds.z >= cameraBounds.x) && (cameraBounds.y + cameraBounds.w >= rendererBounds.y && rendererBounds.y + rendererBounds.w >= cameraBounds.y);
}

void RenderManager::SetMainCamera(Camera* camera){
    mainCamera = camera;
}

// TODO: make sure it has renderer
void RenderManager::AddRenderer(Renderer* renderer){
    mRenderers.push_back(renderer);
}

void RenderManager::RemoveRenderer(Renderer* renderer){
    // For faster removing right now i am doing it this way, later if needed a z-buffer might have to use .erase
    auto it = std::find(mRenderers.begin(), mRenderers.end(), renderer);
    if(it != mRenderers.end()){
        *it = mRenderers.back();
        mRenderers.pop_back();
    }
}