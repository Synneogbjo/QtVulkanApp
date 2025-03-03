#include "object.h"

object::object()
{
    mMesh = new VkTriangleSurface();

    mName = "tbd";
    mCollisionRadius = 0.f;
}

object::object(const std::string& meshFileName, const std::string& name, const float& collisionRadius)
{
    mMesh = new VkTriangleSurface(meshFileName);

    mName = name;
    mCollisionRadius = collisionRadius;
}
