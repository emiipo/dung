#pragma once
#include <vector>

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

    bool CheckAABB(Collider* collider, Collider* other);
};