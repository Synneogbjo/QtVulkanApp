#ifndef TELEPORTER_H
#define TELEPORTER_H

#include "triggerobject.h"

class Teleporter : public TriggerObject
{
private:
    QVector3D mTeleportTargetPosition;

public:
    Teleporter(const std::string& name = "tbd", Collider* collider = nullptr, const std::string& meshFileName = "", Collider* triggerCollider = nullptr, const QVector3D TeleportTargetPosition = QVector3D(0.f,0.f,0.f));

    virtual bool EnteredTrigger(object* other) override;
    virtual bool InTrigger(object* other) override;
    virtual bool LeftTrigger(object* other) override;

};

#endif // TELEPORTER_H
