#ifndef OBJECT_H
#define OBJECT_H

#include "../vktrianglesurface.h"
#include "../Collision/collider.h"

class object : public VkTriangleSurface
{
private:
    friend class RenderWindow;

public:
    object(const std::string& name = "tbd", Collider* collider = nullptr, const std::string& meshFileName = "");

    virtual ~object() = default;

    Collider* mCollider { nullptr };

    virtual void UpdateColliderLocation();
    QVector3D GetLocation();

};

#endif // OBJECT_H
