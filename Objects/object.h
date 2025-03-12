#ifndef OBJECT_H
#define OBJECT_H

#include "../vktrianglesurface.h"

class Collider;

class object : public VkTriangleSurface
{
private:
    friend class RenderWindow;

public:
    object(const std::string& name = "tbd", Collider* collider = nullptr, const std::string& meshFileName = "");

    virtual ~object() = default;

    Collider* mCollider;

    void UpdateColliderLocation();
};

#endif // OBJECT_H
