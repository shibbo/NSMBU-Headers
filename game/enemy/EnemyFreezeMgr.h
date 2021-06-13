#pragma once

#include "types.h"

class Actor;
class Enemy;

class EnemyFreezeMgr 
{
public:
    struct Info 
    {
        u32 mSettings;   // 0    Bits: 0: Horizontally Large, 1: Vertically Large
        Vec3 mPosition;  // 4
        Vec3 mScale;     // 10
        u32 _1C;
    };

    struct Flags 
    {
        u8 mBreakTime;           // 0    Stored in _34
        u8 _1;
        u8 _2;
    };

public:
    EnemyFreezeMgr(Enemy* pOwner);

    bool freeze(const Info& rInfo, u32 count);

    void setFlags(const Flags& rFlags);

    u8 mIceActorCount;      // 0
    u32 mIceActorIds[12];   // 4
    u8 mBreakTime;          // 34
    u8 _35;                 // 35   gravity related
    u8 _36;                 // 36   ^
    u32 _38;                // 38
    Enemy* mOwner;          // 3C
    s16 _40;
    u16 _42;
    u16 _44;
    u16 _46;
    u8 _48;
    u8 _49;
    u8 _4A;
    u8 _4B;
    u8 _4C;
};