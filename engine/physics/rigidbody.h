#pragma once
#include "../components/component.h"

class Transform;
struct Vector2;

class Rigidbody : public Component {
public:
    Rigidbody();

    void Init() override;

    // Later sort out proper physics but for now just simple move. This one works by adding to current pos
    void AddPos(Vector2 velocity);
    Vector2 GetOldPosition() const;
    Vector2 GetNewPosition() const;
private:
    Transform* mTransform{ nullptr };

    Vector2 mOldPosition;
    Vector2 mNewPosition;
};