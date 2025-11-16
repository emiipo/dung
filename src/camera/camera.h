#pragma once
#include <SDL3/SDL.h>
#include "../components/game_object.h"

class Camera : public GameObject{
public:
    Camera(float x, float y, int width, int height);
    ~Camera();

private:
    int mWidth;
    int mHeight;
};