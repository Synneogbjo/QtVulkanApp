#ifndef COLLIDER_H
#define COLLIDER_H

#include "QVector3D"

class Collider
{
public:
    Collider(QVector3D location);

    QVector3D mLocation;

    virtual bool checkCollision(Collider& other) = 0;
    virtual bool checkCollisionWithAABB(class AABBCollider& aabb) = 0;
    virtual bool checkCollisionWithSphere(class SphereCollider& sphere) = 0;

    void SetLocation(QVector3D location);
    QVector3D GetLocation();
};

#endif // COLLIDER_H
