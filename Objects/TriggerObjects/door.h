#ifndef DOOR_H
#define DOOR_H

#include "triggerobject.h"

class Door : public TriggerObject
{
private:
    QVector3D mPivotPoint;
    bool bIsOpen = false;
    bool bDisableCollider = false;
    bool bHasBeenTriggered = false;

public:
    Door(const std::string& name = "tbd", Collider* collider = nullptr, const std::string& meshFileName = "", Collider* triggerCollider = nullptr, const bool bDisableCollisionWhenOpened = true);

    virtual bool EnteredTrigger(object* other) override;
    virtual bool InTrigger(object* other) override;
    virtual bool LeftTrigger(object* other) override;

    void OpenDoor(const QVector3D& pivotPoint);
    void CloseDoor(const QVector3D& pivotPoint);
    void ToggleDoor(const QVector3D& pivotPoint);

    void SetPivotPoint(const QVector3D& pivotPoint);
    QVector3D GetPivotPoint();
};

#endif // DOOR_H
