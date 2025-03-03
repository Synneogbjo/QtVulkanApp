#include "lerp.h"

lerp::lerp() {}

VKVertex lerp::Lerp(float t, VKVertex* point1, VKVertex* point2)
{
    if (!point1 || !point2) return {0,0,0,0,0,0,0,0};

    return (*point1 * (1.f - t)) + (*point2 * (t));
}
