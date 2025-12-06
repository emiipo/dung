#include "camera.h"
#include "../util/common.h"

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

Vector2 Camera::GetDimensions(){
    return {(float)mWidth, (float)mHeight};
}