#pragma once
#include "../components/component.h"
#include "../util/common.h"

class Transform;
class Collider;

class Rigidbody : public Component {
public:
    friend class PhysicsManager;

    Rigidbody();

    void Init() override;

    // Later sort out proper physics but for now just simple move. This one works by adding to current pos
    void AddVelocity(Vector2 velocity);
    Vector2 GetOldPosition() const;
    Vector2 GetNewPosition() const;

    Collider* const& collider = mCollider;
private:
    Transform* mTransform{ nullptr };
    Collider* mCollider{ nullptr };

    Vector2 mOldPosition;
    Vector2 mNewPosition;

    void ApplyMove();
    void DenyMove();
};