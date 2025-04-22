#ifndef BARYCENTRIC_H
#define BARYCENTRIC_H

#include <QVector3D>
#include "HeightMap.h"

// All code made by Marcelo. Thanks for sharing it with me!

class barycentric
{
public:
    barycentric();

    static float getPositionInTerrain(HeightMap* Terrain, float PositionX, float PositionZ);
    static QVector3D BarycentricCoordinates(QVector2D ObjPos, QVector2D p0, QVector2D p1, QVector2D p2);
};

#endif // BARYCENTRIC_H
