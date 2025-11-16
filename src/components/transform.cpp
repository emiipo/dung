#include "transform.h"

Transform::Transform(float x, float y){
    this->x = x;
    this->y = y;
}

Transform::~Transform(){

}

void Transform::SetPosition(float newX, float newY){
    x = newX;
    y = newY;
}