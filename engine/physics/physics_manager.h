#pragma once
#include <vector>
#include "../util/common.h"

class Rigidbody;
class Collider;

class PhysicsManager {
public:
    void HandlePhysics();

    void RegisterRigidbody(Rigidbody* rigidbody);
    void RegisterCollider(Collider* collider);
private:
    //Maybe make it into sets since they should be unique?
    std::vector<Rigidbody*> mRigidbodies;
    std::vector<Collider*> mColliders;

    // later do an out hit info thingy and velocity * deltatime which we dont have rn
    bool CheckCollision(Rigidbody* rigidbody);
    bool CheckAABB(Vector4 colliderBounds, Vector4 otherBounds);
};