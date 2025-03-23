#include "teleporter.h"
#include "../player.h"

Teleporter::Teleporter(const std::string& name, Collider* collider, const std::string& meshFileName, Collider* triggerCollider, const QVector3D teleportTargetPosition) : TriggerObject(name, collider, meshFileName, triggerCollider)
{
    mTeleportTargetPosition = teleportTargetPosition;
}

bool Teleporter::EnteredTrigger(object* other)
{
    qDebug() << "Teleport!";

    if (mTeleportTargetPosition != QVector3D(0.f,0.f,0.f))
    {
        if (auto player = dynamic_cast<Player*>(other))
        {
            player->mMatrix.translate(mTeleportTargetPosition - other->GetLocation());
            //TODO: Swap active camera when player is teleported into the house
            //player->camera

            return true;
        }
    }

    return false;
}

bool Teleporter::InTrigger(object* other)
{
    EnteredTrigger(other);

    return true;
}

bool Teleporter::LeftTrigger(object* other)
{
    return true;
}
