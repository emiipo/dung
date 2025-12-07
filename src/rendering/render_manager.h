#pragma once
#include <SDL3/SDL.h>
#include <list>
#include "../components/world_object.h"
#include "../components/transform.h"
#include "../util/common.h"
#include "camera.h"

class RenderManager {
public:
    RenderManager(SDL_Window* mainWindow, bool renderDebug = false);
    ~RenderManager();

    void Render();

    void RendererAdd(WorldObject* obj);
    void RendererRemove(WorldObject* obj);

    void SetMainCamera(Camera* camera);

private:
    void RenderEntity(WorldObject* entity);
    void RenderDebug(WorldObject* entity);

    bool CheckOverlap(WorldObject* entity);

    SDL_Renderer* mainRenderer{ nullptr };
    Camera* mainCamera{ nullptr };

    bool renderDebug{ false };

    std::list<WorldObject*> mEntitiesToRender;
};