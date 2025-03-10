#include "aabbcollider.h"
#include "spherecollider.h"

AABBCollider::AABBCollider() : Collider({0.f,0.f,0.f}) {}
AABBCollider::AABBCollider(QVector3D location, QVector3D min, QVector3D max) : Collider(location)
{
    mMin = min;
    mMax = max;
}

bool AABBCollider::checkCollision(Collider& other)
{
    return other.checkCollisionWithAABB(*this);
}

bool AABBCollider::checkCollisionWithAABB(AABBCollider& aabb)
{
    return  (mMin.x() + mLocation.x()) <= (aabb.mMax.x() + aabb.mLocation.x()) && (mMax.x() + mLocation.x()) >= (aabb.mMin.x() + aabb.mLocation.x()) &&
            (mMin.y() + mLocation.y()) <= (aabb.mMax.y() + aabb.mLocation.y()) && (mMax.x() + mLocation.y()) >= (aabb.mMin.y() + aabb.mLocation.y()) &&
            (mMin.z() + mLocation.z()) <= (aabb.mMax.z() + aabb.mLocation.z()) && (mMax.x() + mLocation.z()) >= (aabb.mMin.z() + aabb.mLocation.z());
}

bool AABBCollider::checkCollisionWithSphere(SphereCollider& sphere)
{
    float closestX = std::max(mMin.x() + mLocation.x(), std::min(sphere.mCenter.x() + sphere.mLocation.x(), mMax.x() + mLocation.x()));
    float closestY = std::max(mMin.y() + mLocation.y(), std::min(sphere.mCenter.y() + sphere.mLocation.y(), mMax.y() + mLocation.y()));
    float closestZ = std::max(mMin.z() + mLocation.z(), std::min(sphere.mCenter.z() + sphere.mLocation.z(), mMax.z() + mLocation.z()));

    float distance = sqrt(  pow(closestX - (sphere.mCenter.x() + sphere.mLocation.x()),2) +
                            pow(closestY - (sphere.mCenter.y() + sphere.mLocation.y()),2) +
                            pow(closestZ - (sphere.mCenter.z() + sphere.mLocation.z()),2));

    return (distance <= sphere.mRadius);
}
