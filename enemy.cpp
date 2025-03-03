#include "enemy.h"

Enemy::Enemy()
{
    mMesh = new VkTriangleSurface();

    mName = "tbd";
    mCollisionRadius = 0.f;

    mPathVertices = {};
    mMoveSpeed = 1.f;
}

Enemy::Enemy(const std::string meshFileName, const std::string& name, const float& collisionRadius, const std::vector<VKVertex>& pathVertices, const float moveSpeed)
{
    mMesh = new VkTriangleSurface(meshFileName);

    mName = name;
    mCollisionRadius = collisionRadius;

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

    auto oldLocation = mMesh->mMatrix.column(3);
    VKVertex newLocation = Lerper->Lerp(mPathLocation - startIndex, point1, point2);

    mMesh->mMatrix.translate(newLocation.x - oldLocation.x(), newLocation.y - oldLocation.y(), newLocation.z - oldLocation.z());
}
