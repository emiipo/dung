#pragma once
#include <SDL3/SDL.h>
#include <list>
#include "../components/world_object.h"
#include "camera.h"

class RenderManager {
public:
    RenderManager(SDL_Window* mainWindow);
    ~RenderManager();

    void Render();

    void RendererAdd(WorldObject* obj);
    void RendererRemove(WorldObject* obj);

    void SetMainCamera(Camera* camera);

private:
    void RenderEntity(WorldObject* entity);

    SDL_Renderer* mainRenderer{ nullptr };
    Camera* mainCamera{ nullptr };

    std::list<WorldObject*> mEntitiesToRender;
};