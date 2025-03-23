#include "triggerobject.h"

TriggerObject::TriggerObject(const std::string& name, Collider* collider, const std::string& meshFileName, Collider* triggerCollider) : object(name, collider, meshFileName)
{
    mTriggerCollider = triggerCollider;
}
