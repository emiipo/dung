#pragma once
#include <vector>
#include "../util/common.h"

class Renderer;
class Collider;
class Camera;
struct SDL_Window;
struct SDL_Renderer;
struct SDL_FRect;

class RenderManager {
public:
    RenderManager(SDL_Window* mainWindow, bool renderDebug = false);
    ~RenderManager();

    void Render();

    void RegisterRenderer(Renderer* renderer);
    void RemoveRenderer(Renderer* renderer);

    void SetMainCamera(Camera* camera);

private:
    void RenderEntity(Renderer* renderer);
    void RenderDebug(Collider* collider);

    bool CheckOverlap(Renderer* renderer);

    SDL_Renderer* mainRenderer{ nullptr };
    Camera* mainCamera{ nullptr };
    Vector4 cameraBounds{ 0,0,0,0 };

    bool renderDebug{ false };
    SDL_FRect debugRect;

    std::vector<Renderer*> mRenderers;
    // Since we replace it keep it here for now, would need to remove if we decide to multi thread
    Vector4 rendererBounds{ 0,0,0,0 };
};