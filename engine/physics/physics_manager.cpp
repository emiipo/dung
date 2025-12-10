#include "physics_manager.h"
#include "../util/common.h"
#include "collider.h"
#include "rigidbody.h"
#include "../components/transform.h"

void PhysicsManager::HandlePhysics() {
    //Make a Vector2.zero this here for now
    Vector2 zero = {0,0};
    for (Rigidbody* rigidbody : mRigidbodies){
        if(rigidbody->velocity != zero){
            if(!CheckCollision(rigidbody)){
                rigidbody->transform->AddPosition(rigidbody->velocity);
            }
            rigidbody->velocity = {0,0};
        }
    }
}

void PhysicsManager::RegisterRigidbody(Rigidbody* rigidbody) {
    mRigidbodies.push_back(rigidbody);
}

void PhysicsManager::RegisterCollider(Collider* collider) {
    mColliders.push_back(collider);
}

bool PhysicsManager::CheckCollision(Rigidbody* rigidbody){
    // For now checking them all BUT eventually implement spatial partitioning
    for(Collider* collider : mColliders){
        if(collider == rigidbody->collider) continue;
        Vector4 oldBounds = rigidbody->collider->GetBounds();
        Vector4 newBounds = {oldBounds.x + rigidbody->velocity.x, oldBounds.y + rigidbody->velocity.y, oldBounds.z, oldBounds.w};
        if(CheckAABB(newBounds, collider->GetBounds())){
            return true;
        }
    }
    return false;
}

bool PhysicsManager::CheckAABB(Vector4 colliderBounds, Vector4 otherBounds){
    return (colliderBounds.x + colliderBounds.z > otherBounds.x && otherBounds.x + otherBounds.z > colliderBounds.x) && (colliderBounds.y + colliderBounds.w > otherBounds.y && otherBounds.y + otherBounds.w > colliderBounds.y);
}