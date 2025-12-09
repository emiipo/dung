#include "rigidbody.h"
#include "../util/common.h"
#include "../components/game_object.h"
#include "../components/transform.h"

Rigidbody::Rigidbody(){

}

void Rigidbody::Init(){
    mTransform = gameObject->GetComponent<Transform>();
}

void Rigidbody::AddPos(Vector2 velocity){
    mOldPosition = mTransform->position;
    mNewPosition = mOldPosition + velocity;
}

Vector2 Rigidbody::GetOldPosition() const{
    return mOldPosition;
}

Vector2 Rigidbody::GetNewPosition() const{
    return mNewPosition;
}