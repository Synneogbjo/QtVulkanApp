#include "object.h"

#include "../Collision/collider.h"

object::object(const std::string& name, Collider* collider, const std::string& meshFileName) : VkTriangleSurface(meshFileName)
{
    mName = name;
    mCollider = collider;
}

void object::UpdateColliderLocation()
{
    mCollider->mLocation = QVector3D(mMatrix(0,3),mMatrix(1,3),mMatrix(2,3));
}
