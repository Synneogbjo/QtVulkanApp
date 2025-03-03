#ifndef LERP_H
#define LERP_H

#include "vkvertex.h"

class lerp
{
public:
    lerp();

    VKVertex Lerp(float t, VKVertex* point1, VKVertex* point2);
};

#endif // LERP_H
