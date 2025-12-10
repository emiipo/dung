#include "transform.h"

Transform::Transform(float x, float y){
    SetPosition({x, y});
}

void Transform::SetPosition(Vector2 newPosition){
    position = newPosition;
}

void Transform::AddPosition(Vector2 additionalPosition){
    position = position + additionalPosition;
}