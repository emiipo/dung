#include "transform.h"

Transform::Transform(float x, float y){
    position.x = x;
    position.y = y;
}

Transform::~Transform(){

}

void Transform::SetPosition(float newX, float newY){
    position.x = newX;
    position.y = newY;
}