#pragma once
#include <SDL3/SDL.h>
#include "../components/world_object.h"
#include "../util/common.h"

class Camera : public WorldObject{
public:
    Camera(float x, float y, int width, int height);

    void SetFollowTarget(WorldObject* target);
    void ClearFollowTarget();

    void Update();

    Vector2 GetDimensions();
private:
    int mWidth;
    int mHeight;

    WorldObject* followTarget{ nullptr };
};