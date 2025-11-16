#pragma once
#include <SDL3/SDL.h>

class Camera {
public:
    Camera(float x, float y, int width, int height);
    ~Camera();

private:
    int mWidth;
    int mHeight;
};