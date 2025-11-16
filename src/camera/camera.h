#pragma once
#include <SDL3/SDL.h>

class Camera {
public:
    Camera();
    ~Camera();

private:
    int mWidth{ 640 };
    int mHeight{ 480 };
};