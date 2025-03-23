#ifndef COLLIDER_H
#define COLLIDER_H

#include "QVector3D"

class Collider
{
private:
    QVector3D mLocationLocal;
    QVector3D mLocation;
    bool bIsTrigger { true };

public:
    Collider(QVector3D locationLocal, bool bTrigger = true);

    bool bIsEnabled { true };

    virtual bool checkCollision(Collider& other) = 0;
    virtual bool checkCollisionWithAABB(class AABBCollider& aabb) = 0;
    virtual bool checkCollisionWithSphere(class SphereCollider& sphere) = 0;

    void SetLocationLocal(QVector3D locationLocal);
    QVector3D GetLocationLocal();

    void SetLocation(QVector3D locationLocal);
    QVector3D GetLocation();

    void SetIsTrigger(bool bTrigger);
    bool GetIsTrigger();
};

#endif // COLLIDER_H
