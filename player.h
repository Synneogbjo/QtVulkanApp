#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"

class Player : public object
{
public:
    Player();
    Player(const std::string& meshFileName, const std::string& name = "tbd", const float& collisionRadius = 0.f);
};

#endif // PLAYER_H
