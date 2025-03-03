#ifndef ENEMY_H
#define ENEMY_H

#include "object.h"
#include "vkvertex.h"
#include "lerp.h"
#include <vector>

class Enemy : public object
{
private:
    std::vector<VKVertex> mPathVertices;
    float mMoveSpeed;
    float mPathLocation = 0.0f;

    lerp* Lerper = new lerp();


public:   
    Enemy();
    Enemy(const std::string meshFileName, const std::string& name = "tbd", const float& collisionRadius = 0.f, const std::vector<VKVertex>& pathVertices = {}, const float moveSpeed = 1.f);

    void MoveAlongPath();
};

#endif // ENEMY_H
