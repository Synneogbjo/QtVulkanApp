#ifndef AABBCOLLIDER_H
#define AABBCOLLIDER_H

#include "QVector3D"
#include "collider.h"

class AABBCollider : public Collider
{
public:
    AABBCollider();

    QVector3D mMin;
    QVector3D mMax;

    AABBCollider(QVector3D location, QVector3D min, QVector3D max);

    virtual bool checkCollision(Collider& other) override;
    virtual bool checkCollisionWithAABB(class AABBCollider& other) override;
    virtual bool checkCollisionWithSphere(class SphereCollider& other) override;
};

#endif // AABBCOLLIDER_H
