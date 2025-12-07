#pragma once

class GameObject;

class Component {
public:
    friend class GameObject;

    virtual ~Component();

    virtual void Init(){};

    GameObject* const& gameObject = mCreator;
private:
    GameObject* mCreator{ nullptr };
};