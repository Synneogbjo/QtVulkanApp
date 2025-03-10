#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"

class Player : public object
{
public:
    Player(const std::string& name = "tbd", Collider* collider = nullptr, const std::string& meshFileName = "");
};

#endif // PLAYER_H
