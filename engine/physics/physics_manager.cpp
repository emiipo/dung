#include "physics_manager.h"

void PhysicsManager::HandlePhysics() {
    for (Rigidbody* rigidbody : mRigidbodies){
        if(rigidbody->GetOldPosition() != rigidbody->GetNewPosition()){
            // For now checking them all BUT eventually implement spatial partitioning
            for(Collider* collider : mColliders){
                
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