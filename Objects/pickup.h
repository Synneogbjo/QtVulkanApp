#ifndef PICKUP_H
#define PICKUP_H

#include "object.h"

class Pickup : public object
{
public:
    Pickup(const std::string& name = "tbd", Collider* collider = nullptr, const std::string& meshFileName = "");

    int mMeshIndex;
};

#endif // PICKUP_H
