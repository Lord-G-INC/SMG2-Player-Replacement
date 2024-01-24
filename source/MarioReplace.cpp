#include "kamek/hooks.h"
#include "PlayerFollowActor.h"
#include "Game/Util.h"
#include "Game/Player.h"
PlayerFollowActor *pfa;

// Included from PTD
void *loadArcAndFile(const char *pArc, const char *pFile) {
    JKRArchive* arc = MR::mountArchive(pArc, MR::getStationedHeapGDDR3(), false);
	void* file = arc->getResource(pFile);

	if (arc && file) 
		return file;
	else 
		OSReport("(PTD Archive Loader) %s %s isn't exist!\n", pArc, pFile);

	return 0;
}

JMapInfoIter *makeIterForFollowActor () {
    void *bcsvToRead = loadArcAndFile("/ObjectData/PlayerFollowActor.arc", "/InfoForReplacementIter.bcsv");
    JMapInfo *info = new JMapInfo();
    info->attach(bcsvToRead);
    return new JMapInfoIter(info, 0);
}

PlayerFollowActor::PlayerFollowActor(const char *pName) : LiveActor(pName) {}
void PlayerFollowActor::init(const JMapInfoIter &rIter) {
    MR::processInitFunction(this, rIter, false);
    MR::connectToSceneMapObj(this);
    LiveActor::makeActorAppeared();
    MR::invalidateClipping(this);
}
void PlayerFollowActor::control() {}

void pfa_doFunniStuff () { // Basically PlayerFollowActor::control
    TVec3f *mPos = new TVec3f(*MR::getPlayerPos());
    TVec3f *mRot = new TVec3f(*MR::getPlayerRotate());
    MR::setPosition(pfa, *mPos);
    MR::setRotation(pfa, *mRot);

    MarioHolder *mh = MR::getMarioHolder();
    MarioActor *ma = mh->getMarioActor();
    MR::startBckIfExist(pfa, ma->mModelManager->getPlayingBckName());
    ma->mScale = TVec3f(0);
}

void createPlayerFollowActor () {
    pfa = new PlayerFollowActor("PlayerFollowActor");
    pfa->init(*makeIterForFollowActor());
}

kmBranch(0x804517E0, createPlayerFollowActor);
kmBranch(0x803C1C5C, pfa_doFunniStuff);