#pragma once
#include "../components/component.h"

class Transform;

class Rigidbody : public Component {
public:
    Rigidbody();

    void Init() override;
private:
    Transform* mTransform{ nullptr };
};