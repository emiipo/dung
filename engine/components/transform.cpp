#include "transform.h"

Transform::Transform(float x, float y){
    SetPosition(x, y);
}

void Transform::SetPosition(float newX, float newY){
    position.x = newX;
    position.y = newY;
}