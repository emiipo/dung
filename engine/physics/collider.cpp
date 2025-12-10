#include "collider.h"
#include "../components/game_object.h"
#include "../components/transform.h"
#include "../core/app.h"

Collider::Collider(float width, float height, float offsetX, float offsetY){
    mSize.x = width;
    mSize.y = height;
    mOffset.x = offsetX;
    mOffset.y = offsetY;
}

//Disable if transform doesnt exist
void Collider::Init(){
    mTransform = gameObject->GetComponent<Transform>();

    Application::Instance->GetPhysicsManager().RegisterCollider(this);
}

Vector4 Collider::GetBounds() const{
    if(!mTransform) return {0,0,0,0};
    return {mTransform->position.x + mOffset.x, mTransform->position.y + mOffset.y, mSize.x, mSize.y};
}

Vector2 Collider::GetPosition() const{
    if(!mTransform) return {0,0};
    return {mTransform->position.x + mOffset.x, mTransform->position.y + mOffset.y};
}

Vector2 Collider::GetOffset() const{
    return {mOffset.x, mOffset.y};
}

Vector2 Collider::GetSize() const{
    return {mSize.x, mSize.y};
}   