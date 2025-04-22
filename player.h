#ifndef PLAYER_H
#define PLAYER_H

#include "ObjMesh.h"
#include "HeightMap.h"

class Player : public ObjMesh
{
public:
    Player(const std::string& filename, const std::string& texturefilename = "") : ObjMesh(filename, texturefilename){}

    void move(float x, float y = 0.0f, float z = 0.0f, HeightMap* terrain = {});
};

#endif // PLAYER_H
