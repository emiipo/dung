#include "rigidbody.h"
#include "../util/common.h"
#include "../components/game_object.h"
#include "../components/transform.h"
#include "../core/app.h"

Rigidbody::Rigidbody(){

}

void Rigidbody::Init(){
    mTransform = gameObject->GetComponent<Transform>();
    mCollider = gameObject->GetComponent<Collider>();

    mOldPosition = mTransform->position;
    mNewPosition = mOldPosition;

    Application::Instance->GetPhysicsManager().RegisterRigidbody(this);
}

void Rigidbody::AddVelocity(Vector2 velocity){
    mOldPosition = mTransform->position;
    mNewPosition = mOldPosition + velocity;
}

// See if instead we could use AddPosition and add the velocities position, we dont store it so doing this for now
void Rigidbody::ApplyMove(){
    mOldPosition = mNewPosition;
    mTransform->SetPosition(mNewPosition);
}

void Rigidbody::DenyMove(){
    mNewPosition = mOldPosition;
}

Vector2 Rigidbody::GetOldPosition() const{
    return mOldPosition;
}

Vector2 Rigidbody::GetNewPosition() const{
    return mNewPosition;
}