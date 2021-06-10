#pragma once

#include "nsmb/collision/TileChecker.h"
#include "sead.h"

class StageActor;

class PhysicsMgr : public TileChecker
{
    SEAD_RTTI_BASE(PhysicsMgr)
public:
    struct Sensor
    {
        f32 mPoint1;             // _0
        f32 mPoint2;             // _4
        f32 mDistanceFromCenter; // _8
    };

    PhysicsMgr();

    virtual ~PhysicsMgr();
    virtual void processCollisions();
    virtual void vf2C();
    virtual void vf34();
    virtual u32 vf3C() = 0;
    virtual u32 vf44() = 0;
    virtual u32 vf4C() = 0;
    virtual void vf54();
    virtual void vf5C();
    virtual void vf64();
    virtual void vf6C();

    u8 _4C[0x890 - 0x4C];
    StageActor* mOwner;         // _890
    u32 _894;
    Vec3* mPosition;            // _898
    Vec3* mLastPosition;        // _89C
    u8* mLayer;                 // _8A0
    u8* mCollisionMask;         // _8A4
    s8* mPlayerId;              // _8A8
    u32 _8AC;

    u8 _8B0[0x14DC - 0x8B0];
};