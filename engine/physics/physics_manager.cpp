#include "physics_manager.h"
#include "../util/common.h"
#include "collider.h"
#include "rigidbody.h"

void PhysicsManager::HandlePhysics() {
    // REfine this later just want it to work now
    bool hasCollided = false;
    for (Rigidbody* rigidbody : mRigidbodies){
        if(rigidbody->GetOldPosition() != rigidbody->GetNewPosition()){
            hasCollided = false;
            // For now checking them all BUT eventually implement spatial partitioning
            for(Collider* collider : mColliders){
                if(collider == rigidbody->collider) continue;
                if(CheckAABB(rigidbody->collider, collider)){
                    hasCollided = true;
                    break;
                }
            }
            if(hasCollided){
                rigidbody->DenyMove();
            }
            else{
                rigidbody->ApplyMove();
            }
        }
    }
}

void PhysicsManager::RegisterRigidbody(Rigidbody* rigidbody) {
    mRigidbodies.push_back(rigidbody);
}

void PhysicsManager::RegisterCollider(Collider* collider) {
    mColliders.push_back(collider);
}

bool PhysicsManager::CheckAABB(Collider* collider, Collider* other){
    Vector4 colliderBounds = collider->GetBounds();
    Vector4 otherBounds = other->GetBounds();
    return (colliderBounds.x + colliderBounds.z >= otherBounds.x && otherBounds.x + otherBounds.z >= colliderBounds.x) && (colliderBounds.y + colliderBounds.w >= otherBounds.y && otherBounds.y + otherBounds.w >= colliderBounds.y);
}