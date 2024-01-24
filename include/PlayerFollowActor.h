#pragma once

#include "Game/LiveActor/LiveActor.h"

class PlayerFollowActor : public LiveActor {
public:
    PlayerFollowActor(const char *pName);
    virtual void init(const JMapInfoIter &rIter);
    virtual void control();
};