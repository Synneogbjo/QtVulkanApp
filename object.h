#ifndef OBJECT_H
#define OBJECT_H

#include "vktrianglesurface.h"

class object
{
private:
    friend class RenderWindow;

public:
    object();
    object(const std::string& meshFileName, const std::string& name = "tbd", const float& collisionradius = 0.f);

    std::string mName;
    float mCollisionRadius;

    VkTriangleSurface* mMesh;
};

#endif // OBJECT_H
