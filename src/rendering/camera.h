#pragma once
#include <SDL3/SDL.h>
#include "../components/world_object.h"

class Camera : public WorldObject{
public:
    Camera(float x, float y, int width, int height);

private:
    int mWidth;
    int mHeight;
};