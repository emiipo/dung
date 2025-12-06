#pragma once

class GameObject;

class Component {
public:
    friend class GameObject;

    virtual ~Component();

    GameObject* const& gameObject = mCreator;
private:
    GameObject* mCreator{ nullptr };
};