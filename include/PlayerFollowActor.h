#pragma once

#include "syati.h"

class PlayerFollowActor : public LiveActor {
public:
    PlayerFollowActor(const char *pName);
    virtual void init(const JMapInfoIter &rIter);
    virtual void control();
    virtual void appear();
    virtual void kill();
};