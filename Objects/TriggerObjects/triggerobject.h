#ifndef TRIGGEROBJECT_H
#define TRIGGEROBJECT_H

#include "../object.h"

class TriggerObject : public object
{
public:
    TriggerObject(const std::string& name = "tbd", Collider* collider = nullptr, const std::string& meshFileName = "", Collider* triggerCollider = nullptr);

    Collider* mTriggerCollider { nullptr };

    virtual bool EnteredTrigger(object* other) = 0;
    virtual bool InTrigger(object* other) = 0;
    virtual bool LeftTrigger(object* other) = 0;
};

#endif // TRIGGEROBJECT_H
