#pragma once

#include "revolution.h"
#include "Game/AreaObj/AreaObj.h"
#include "Game/NameObj/NameObjFactory.h"
#include "PlayerFollowActor.h"

namespace {
    template<typename T>
    NameObj* createExtActor(const char *pName) {
        return new T(pName);
    }

    const CreateActorEntry cNewCreateNameObjTable[] = {
        { "PlayerFollowActor", createExtActor<PlayerFollowActor> }
    };

    const s32 cNewCreateNameObjTableCount = sizeof(cNewCreateNameObjTable) / sizeof(CreateActorEntry);
};