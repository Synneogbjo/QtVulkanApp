#include "spherecollider.h"
#include "aabbcollider.h"

SphereCollider::SphereCollider() : Collider({0.f,0.f,0.f}) {}


SphereCollider::SphereCollider(QVector3D location, QVector3D center, float radius) : Collider(location)
{
    mCenter = center;
    mRadius = radius;
}

bool SphereCollider::checkCollision(Collider& other)
{
    return other.checkCollisionWithSphere(*this);
}

bool SphereCollider::checkCollisionWithAABB(AABBCollider& aabb)
{
    return aabb.checkCollisionWithSphere(*this);
}

bool SphereCollider::checkCollisionWithSphere(SphereCollider& sphere)
{
    float distance = sqrt(  pow((mCenter.x() + mLocation.x()) - (sphere.mCenter.x() + sphere.mLocation.x()),2) +
                            pow((mCenter.y() + mLocation.y()) - (sphere.mCenter.y() + sphere.mLocation.y()),2) +
                            pow((mCenter.z() + mLocation.z()) - (sphere.mCenter.z() + sphere.mLocation.z()),2));

    return (distance <= mRadius + sphere.mRadius);
}
