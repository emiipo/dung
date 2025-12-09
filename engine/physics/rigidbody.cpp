#include "rigidbody.h"
#include "../components/game_object.h"
#include "../components/transform.h"

Rigidbody::Rigidbody(){

}

void Rigidbody::Init(){
    mTransform = gameObject->GetComponent<Transform>();
}