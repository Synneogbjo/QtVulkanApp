#include "aabbcollider.h"
#include "spherecollider.h"

AABBCollider::AABBCollider() : Collider({0.f,0.f,0.f}) {}
AABBCollider::AABBCollider(QVector3D location, QVector3D min, QVector3D max, bool bTrigger) : Collider(location, bTrigger)
{
    // Makes sure to always use the smallest values for mMin and the largest for mMax

    mMin.setX(std::min(min.x(), max.x()));
    mMin.setY(std::min(min.y(), max.y()));
    mMin.setZ(std::min(min.z(), max.z()));
    mMax.setX(std::max(min.x(), max.x()));
    mMax.setY(std::max(min.y(), max.y()));
    mMax.setZ(std::max(min.z(), max.z()));
}

bool AABBCollider::checkCollision(Collider& other)
{
    return other.checkCollisionWithAABB(*this);
}

bool AABBCollider::checkCollisionWithAABB(AABBCollider& aabb)
{
    return  (mMin.x() + GetLocation().x()) <= (aabb.mMax.x() + aabb.GetLocation().x()) && (mMax.x() + GetLocation().x()) >= (aabb.mMin.x() + aabb.GetLocation().x()) &&
            (mMin.y() + GetLocation().y()) <= (aabb.mMax.y() + aabb.GetLocation().y()) && (mMax.x() + GetLocation().y()) >= (aabb.mMin.y() + aabb.GetLocation().y()) &&
            (mMin.z() + GetLocation().z()) <= (aabb.mMax.z() + aabb.GetLocation().z()) && (mMax.x() + GetLocation().z()) >= (aabb.mMin.z() + aabb.GetLocation().z());
}

bool AABBCollider::checkCollisionWithSphere(SphereCollider& sphere)
{
    float closestX = std::max(mMin.x() + GetLocation().x(), std::min(sphere.mCenter.x() + sphere.GetLocation().x(), mMax.x() + GetLocation().x()));
    float closestY = std::max(mMin.y() + GetLocation().y(), std::min(sphere.mCenter.y() + sphere.GetLocation().y(), mMax.y() + GetLocation().y()));
    float closestZ = std::max(mMin.z() + GetLocation().z(), std::min(sphere.mCenter.z() + sphere.GetLocation().z(), mMax.z() + GetLocation().z()));

    float distance = sqrt(  pow(closestX - (sphere.mCenter.x() + sphere.GetLocation().x()),2) +
                            pow(closestY - (sphere.mCenter.y() + sphere.GetLocation().y()),2) +
                            pow(closestZ - (sphere.mCenter.z() + sphere.GetLocation().z()),2));

    return (distance <= sphere.mRadius);
}
