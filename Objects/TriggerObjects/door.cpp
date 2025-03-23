#include "door.h"

#include "../player.h"

Door::Door(const std::string& name, Collider* collider, const std::string& meshFileName, Collider* triggerCollider, const bool bDisableCollisionWhenOpened) : TriggerObject(name, collider, meshFileName, triggerCollider)
{
    bDisableCollider = bDisableCollisionWhenOpened;
}

bool Door::EnteredTrigger(object* other)
{
    if (static_cast<Player*>(other))
    {
        OpenDoor(mPivotPoint);
    }

    return true;
}

bool Door::InTrigger(object* other)
{
    if (!bHasBeenTriggered)
    {
        EnteredTrigger(other);
        bHasBeenTriggered = true;
    }

    return true;
}

bool Door::LeftTrigger(object* other)
{
    bHasBeenTriggered = false;

    if (static_cast<Player*>(other))
    {
        CloseDoor(mPivotPoint);
    }

    return true;
}

void Door::OpenDoor(const QVector3D& pivotPoint)
{
    //TODO: Add logic to make the door rotate around the pivot point by translating the matrix

    mMatrix.rotate(35.f,0,1,0);
    bIsOpen = true;

    if (mCollider && bDisableCollider) mCollider->bIsEnabled = false;
}

void Door::CloseDoor(const QVector3D& pivotPoint)
{
    //TODO: Add logic to make the door rotate around the pivot point by translating the matrix

    mMatrix.rotate(-35.f,0,1,0);
    bIsOpen = false;

    if (mCollider && bDisableCollider) mCollider->bIsEnabled = true;
}

void Door::ToggleDoor(const QVector3D& pivotPoint)
{
    bIsOpen ? CloseDoor(pivotPoint) : OpenDoor(pivotPoint);
}

void Door::SetPivotPoint(const QVector3D& pivotPoint)
{
    mPivotPoint = pivotPoint;
}

QVector3D Door::GetPivotPoint()
{
    return mPivotPoint;
}
