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

Vector4 Camera::GetBounds(){
    return {transform->position.x, transform->position.y, (float)mWidth, (float)mHeight};
}

Vector2 Camera::GetPosition(){
    return {transform->position.x, transform->position.y};
}

Vector2 Camera::GetSize(){
    return {(float)mWidth, (float)mHeight};
}