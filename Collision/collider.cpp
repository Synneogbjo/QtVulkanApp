#include "collider.h"

Collider::Collider(QVector3D location)
{
    mLocation = location;
}

void Collider::SetLocation(QVector3D location)
{
    mLocation = location;
}

QVector3D Collider::GetLocation()
{
    return mLocation;
}
