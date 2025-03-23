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

            if (player->cameraRef)
            {
                QMatrix4x4 cam = *(player->cameraRef);
                QVector3D cameraLoc = { cam(0,3), cam(1,3), cam(2,3)};

                qDebug() << cameraLoc;

                //player->cameraRef->translate((mTeleportTargetPosition + QVector3D(0.f,1.f,-35.f)) - cameraLoc);
                player->cameraRef->translate(-mTeleportTargetPosition.x(), mTeleportTargetPosition.y(), mTeleportTargetPosition.z());

                cam = *(player->cameraRef);

                qDebug() << cam(0,3) << cam(1,3) << cam(2,3);
            }

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
