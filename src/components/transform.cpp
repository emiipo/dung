#include "transform.h"

Transform::Transform(float x = 0; float y = 0){
    this->x = x;
    this->y = y;
}

Transform::~Transform(){

}

void Transform::SetPosition(float newX, float newY){
    x = newX;
    y = newY;
}