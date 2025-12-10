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

    velocity = {0, 0};

    Application::Instance->GetPhysicsManager().RegisterRigidbody(this);
}

void Rigidbody::AddVelocity(Vector2 velocity){
    this->velocity = velocity;
}