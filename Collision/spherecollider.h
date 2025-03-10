#ifndef SPHERECOLLIDER_H
#define SPHERECOLLIDER_H

#include "QVector3D"
#include "collider.h"

class SphereCollider : public Collider
{
public:
    SphereCollider();

    QVector3D mCenter;
    float mRadius;

    SphereCollider(QVector3D location, QVector3D center, float radius);

    virtual bool checkCollision(Collider& other) override;
    virtual bool checkCollisionWithAABB(class AABBCollider& other) override;
    virtual bool checkCollisionWithSphere(class SphereCollider& other) override;
};

#endif // SPHERECOLLIDER_H
