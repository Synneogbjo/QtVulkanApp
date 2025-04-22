#include "Player.h"
#include "barycentric.h"

void Player::move(float x, float y, float z, HeightMap* terrain)
{
    qDebug() << "Before: " << mMatrix;

    if (terrain)
    {
        float bary = barycentric::getPositionInTerrain(terrain, mMatrix(0,3) + x, mMatrix(2,3) + z);

        if (bary != -INFINITY)
        {
            mMatrix(1,3) = bary;
        }
        else
        {
            mMatrix.translate(0.f,y,0.f);
        }

    }
    else
    {
        mMatrix.translate(0.f, y, 0.f);
    }

    mMatrix.translate(x,0.f,z);

    qDebug() << "After: " << mMatrix;
}
