#include "enemy.h"

Enemy::Enemy(const std::string& name, Collider* collider, const std::string meshFileName, const std::vector<VKVertex>& pathVertices, const float moveSpeed) : object(name, collider, meshFileName)
{
    mPathVertices = pathVertices;
    mMoveSpeed = moveSpeed;
}

void Enemy::MoveAlongPath()
{
    int pathLength = mPathVertices.size();

    if (pathLength < 2) return;

    mPathLocation += mMoveSpeed;

    if (mPathLocation >= pathLength) mPathLocation -= pathLength;

    int startIndex = (int) mPathLocation;

    VKVertex* point1 = &mPathVertices[startIndex];
    VKVertex* point2 = &mPathVertices[(startIndex + 1) >= pathLength ? 0 : startIndex + 1];

    auto oldLocation = mMatrix.column(3);
    VKVertex newLocation = Lerper->Lerp(mPathLocation - startIndex, point1, point2);

    auto val = (startIndex + 1) >= pathLength? 0 : startIndex + 1;

    mMatrix.translate(newLocation.x - oldLocation.x(), newLocation.y - oldLocation.y(), newLocation.z - oldLocation.z());
}
