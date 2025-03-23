#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"

class Player : public object
{
public:
    Player(const std::string& name = "tbd", Collider* collider = nullptr, const std::string& meshFileName = "");

    QMatrix4x4* cameraRef { nullptr };
};

#endif // PLAYER_H
