#pragma once

#include "types.h"

class Profile;

struct ActorBuildInfo 
{
    u32 mSettings_1;     // _0
    u32 mSettings_2;     // _4
    u32 mParentID;       // _8
    Profile* mProfile;   // _C
    Vec3 mPosition;      // _10
    u32 mRotation;       // _1C
    u8 mLayer;           // _20
    u8 mEventId1;        // _21
    u8 mEventId2;        // _22
    u8 _23;
    u8 mMovementId;      // _24
    u8 mLinkId;          // _25
    u8 mInitStateFlag;   // _26
    u8 _27;              // _27 Padding?
    u8* _28;             // _28
};
