#ifndef PICKUP_H
#define PICKUP_H

#include "object.h"

class Pickup : public object
{
public:
    Pickup();
    Pickup(const std::string& meshFileName, const std::string& name = "tbd", const float& collisionRadius = 0.f);

    int mMeshIndex;
};

#endif // PICKUP_H
