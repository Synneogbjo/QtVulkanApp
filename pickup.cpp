#include "pickup.h"

Pickup::Pickup()
{
    mMesh = new VkTriangleSurface();
    mMeshIndex = -1;

    mName = "tbd";
    mCollisionRadius = 0.f;
}

Pickup::Pickup(const std::string& meshFileName, const std::string& name, const float& collisionRadius)
{
    mMesh = new VkTriangleSurface(meshFileName);
    mMeshIndex = -1;

    mName = name;
    mCollisionRadius = collisionRadius;
}
