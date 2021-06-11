#pragma once

#include "types.h"

struct ChallengeMgrData
{
    void* mDataPtr; // _0
    u8 _4[0x1E18 - 0x4];
};

class ChallengeMgr
{
public:
    u32 _0;
    u32 _4;
    u32 _8;
    u32 _C;
    ChallengeMgrData mMgrData;  // _10
    u32 mChallenge;             // _1E28
    u8 mChallengeType;          // _1E2C
    u8 _1E2D;
    u32 _1E2E;
    u8 _1E32;
    u8 _1E33;
    u32 _1E34;
    u32 mActorID;               // _1E38
    u32 _1E3C;
    u32 _1E40;
    u32 _1E44;
    u32 mChallengeTime;         // _1E48
    u32 _1E4C;
    u8 _1E50;
    u8 _1E51;
    u8 _1E52;
    u8 _1E53;
    u8 _1E54;
    u8 _1E55;
    u8 _1E56;
    u8 _1E57;
    u8 _1E58;
    u8 _1E59;
    u8 _1E5A;
    u8 _1E5B;
    u8 _1E5C[0x1E84 - 0x1E5C];
};
