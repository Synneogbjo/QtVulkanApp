#include "pickup.h"

Pickup::Pickup(const std::string& name, Collider* collider, const std::string& meshFileName) : object(name, collider, meshFileName)
{
    mMeshIndex = -1;
}
