#pragma once
#include <list>
#include "../components/world_object.h"

class RenderManager {
public:
    RenderManager();
    ~RenderManager();

    void Render();

    void RendererAdd(WorldObject obj);
    void RendererRemove(WorldObject obj);

private:
    std::list<WorldObject> mEntitiesToRender;
};