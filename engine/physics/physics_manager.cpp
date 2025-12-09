#include "physics_manager.h"

void PhysicsManager::HandlePhysics() {
    // Go through rigidbodies
    // Check their old and new position
    // Check collision with colliders. Im pretty sure i only need to check distance and only closest colliders i think
}

void PhysicsManager::RegisterRigidbody(Rigidbody* rigidbody) {
    mRigidbodies.push_back(rigidbody);
}

void PhysicsManager::RegisterCollider(Collider* collider) {
    mColliders.push_back(collider);
}