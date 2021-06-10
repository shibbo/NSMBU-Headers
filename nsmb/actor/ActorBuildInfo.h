#pragma once

#include "types.h"

class Profile;

struct ActorBuildInfo 
{
    u32 mSettings_1;                // 0
    u32 mSettings_2;                // 4
    u32 mParentID;                  // 8
    Profile* mProfile;              // C
    Vec3 mPosition;                 // 10
    u32 mRotation;                  // 1C
    u8 mLayer;                      // 20
    u8 mEventId1;                   // 21
    u8 mEventId2;                   // 22
    u8 _23;
    u8 mMovementId;                 // 24
    u8 mLinkId;                     // 25
    u8 mInitStateFlag;              // 26
    u8 _27;
    u8* _28;                        // 28
};