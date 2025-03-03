#include "player.h"

Player::Player()
{
    mMesh = new VkTriangleSurface();

    mName = "tbd";
    mCollisionRadius = 0.f;
}

Player::Player(const std::string& meshFileName, const std::string& name, const float& collisionRadius)
{
    mMesh = new VkTriangleSurface(meshFileName);

    mName = name;
    mCollisionRadius = collisionRadius;
}
