#include "PlayerFollowActor.h"

PlayerFollowActor::PlayerFollowActor (const char *pName) : LiveActor(pName) {

}

void PlayerFollowActor::init (const JMapInfoIter &rIter) {
    MR::processInitFunction(this, rIter, false);
    MR::connectToSceneMapObj(this);
    MR::invalidateClipping(this);
    MR::useStageSwitchSyncAppear(this, rIter);
}

void PlayerFollowActor::appear () {
    MarioAccess::getPlayerActor()->mScale = TVec3f(0);
    LiveActor::appear();
}

void PlayerFollowActor::kill () {
    MarioAccess::getPlayerActor()->mScale = TVec3f(1);
    LiveActor::kill();
}

void PlayerFollowActor::control () {
    TVec3f pPlayerPos = TVec3f(*MR::getPlayerPos());
    TVec3f pPlayerRot = TVec3f(*MR::getPlayerRotate());
    MR::setPosition(this, pPlayerPos);
    MR::setRotation(this, pPlayerRot);

    MarioActor *pMarioActor = MarioAccess::getPlayerActor();
    MR::tryStartAllAnim(this, MR::getPlayingBckName(pMarioActor));
    MR::setAllAnimFrameAndStop(this, MR::getPlayingBckName(pMarioActor), MR::getBckFrame(pMarioActor));
}