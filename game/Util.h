#pragma once

#include "types.h"

namespace Util
{
    static s32 WorldLevelCounts[];
    static s32 ToadHouseCounts[];
    static s32 AmbushCounts[]; 
    static s32 ExitCounts[];

    bool isOnScreen(Rect *pRect);
    bool isOutsideOfZone(Rect *pRect);

    void mapPositionToScreen(Vec2 &, const Vec2 &);

    bool isNormalWorldNum(u32 worldNo);
    bool isCoinBattleWorldNum(u32 worldNo);
    bool isChallengeWorldNum(u32 worldNo);
    bool isCourseLevelNum(u32 levelNo);
    bool isNormalLevelNum(u32 levelNo);
    bool isSecretLevelNum(u32 levelNo);
    bool isGhostHouseLevelNum(u32 levelNo);
    bool isTowerLevelNum(u32 levelNo);
    bool isCastleLevelNum(u32 levelNo);

    s32 getLevelCountInWorld(s32 worldNo);
    s32 getAmbushCountInWorld(s32 worldNo);
    s32 getToadHouseCountInWorld(s32 worldNo);
    s32 getExitCountForWorld(s32 worldNo);

    s32 getIndexForLevelAndWorldNum(u32 worldNo, u32 levelNo, u32);
};