#include "collider.h"
#include "game_object.h"
#include "transform.h"

Collider::Collider(float width, float height, float offsetX, float offsetY){
    mSize.x = width;
    mSize.y = height;
    mOffset.x = offsetX;
    mOffset.y = offsetY;
}

//Disable if transform doesnt exist
void Collider::Init(){
    mTransform = gameObject->GetComponent<Transform>();
}

Vector4 Collider::GetBounds(){
    if(!mTransform) return {0,0,0,0};
    return {mTransform->position.x + mOffset.x, mTransform->position.y + mOffset.y, mSize.x, mSize.y};
}

Vector2 Collider::GetPosition(){
    if(!mTransform) return {0,0};
    return {mTransform->position.x + mOffset.x, mTransform->position.y + mOffset.y};
}

Vector2 Collider::GetOffset(){
    return {mOffset.x, mOffset.y};
}

Vector2 Collider::GetSize(){
    return {mSize.x, mSize.y};
}   