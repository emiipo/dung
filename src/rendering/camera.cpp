#include "camera.h"

// put this in util or smth
const int tilesize = SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE;

Camera::Camera(float x, float y, int width, int height) : WorldObject(false){
    mWidth = width;
    mHeight = height;
}

void Camera::SetFollowTarget(WorldObject* target){
    followTarget = target;
}

void Camera::ClearFollowTarget(){
    followTarget = nullptr;
}

void Camera::Update(){
    if(followTarget){
        transform->SetPosition(followTarget->transform->position.x - (mWidth/2) + (tilesize/2), followTarget->transform->position.y - (mHeight/2) + (tilesize/2));
    }
}