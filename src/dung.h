#pragma once
#include "../engine/core/app.h"

class Rigidbody;

class Dung : public Application{
public:
    void Start() override;
    void Update() override;

    //These should be moved into components etc, here for testing only
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();

private:
    //Delete later, testing
    Transform* t{nullptr};
};