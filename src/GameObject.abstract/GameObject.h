//
// Created by WolfPlay on 10/20/2024.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

namespace Snowflake {

class GameObject {

public:
    GameObject() = default;

    virtual ~GameObject() = default;

    virtual void updateState();

    virtual void draw();
};

} // Snowflake

#endif //GAMEOBJECT_H
