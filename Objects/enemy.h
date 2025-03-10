#ifndef ENEMY_H
#define ENEMY_H

#include "object.h"
#include "../vkvertex.h"
#include "../lerp.h"
#include <vector>

class Enemy : public object
{
private:
    std::vector<VKVertex> mPathVertices;
    float mMoveSpeed;
    float mPathLocation = 0.0f;

    lerp* Lerper = new lerp();


public:
    Enemy(const std::string& name = "tbd", Collider* collider = nullptr, const std::string meshFileName = "", const std::vector<VKVertex>& pathVertices = {}, const float moveSpeed = 1.f);

    void MoveAlongPath();
};

#endif // ENEMY_H
