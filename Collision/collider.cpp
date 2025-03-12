#include "collider.h"

Collider::Collider(QVector3D locationLocal)
{
    mLocationLocal = locationLocal;
}

void Collider::SetLocationLocal(QVector3D locationLocal)
{
    mLocationLocal = locationLocal;
}

QVector3D Collider::GetLocationLocal()
{
    return mLocationLocal;
}

void Collider::SetLocation(QVector3D location)
{
    mLocation = location + mLocationLocal;
}

QVector3D Collider::GetLocation()
{
    return mLocation;
}
