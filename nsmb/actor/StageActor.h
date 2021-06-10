#pragma once

#include "nsmb/actor/ActorBuildInfo.h"
#include "nsmb/actor/BaseActor.h"
#include "nsmb/collision/HitboxCollider.h"
#include "sead.h"

class ActorPhysicsMgr;
class BabyYoshiEatData;
class YoshiEatData;

class StageActor : public BaseActor
{
    SEAD_RTTI_OVERRIDE(StageActor, BaseActor)
public:
    StageActor(const ActorBuildInfo *pInfo);

    virtual ~StageActor();

    virtual void afterCreate(PostArg);

    virtual PreResult beforeExecute();
    virtual void afterExecute(PostArg);

    virtual PreResult beforeDraw();

    virtual void setPlayerId(s8);
    virtual void removeColliders();
    virtual void addColliders();

    virtual ActorPhysicsMgr* getActorPhysicsMgr() const;
    virtual void vfAC();
    virtual u32 vfB4();
    virtual void vfBC();
    virtual void vfC4();
    virtual void vfCC();
    virtual void killAtGoal();
    virtual void splashWater();
    virtual void splashLava();
    virtual void splashLavaWaves();
    virtual void splashPoison();
    virtual bool isOffScreen() const;
    virtual void updateChallengeBumpTimer();
    
    u32 mDirection;                     // _50
    s8 mPlayerID;                       // _54
    s8 mControllerPlayerID;             // _55
    u8 mLayer;                          // _56
    u8 mCollisionMask;                  // _57
    f32 mXSpeed;                        // _58
    f32 _5C;
    f32 mFallSpeed;                     // _60
    f32 mGravity;                       // _64
    f32 mXAcceleration;                 // _68
    Vec3 mPosition;                     // _6C
    Vec3 mSpeed;                        // _78
    Vec3 mMaxSpeed;                     // _84
    Vec3 mScale;                        // _90
    Vec3u mRotation;                    // _9C
    u32 _A8;
    u32 _AC;
    u32 mRotationDelta;                 // _B0
    Vec2 mPositionDelta;                // _B4
    HitboxCollider mHitboxCollider;     // _BC
    Vec2 mVisibleAreaOffs;              // _1E4
    Vec2 mVisibleAreaSize;              // _11EC
    Vec2 mSize;                         // _1F4
    f32 _1FC;
    f32 _200;
    f32 _204;
    f32 _208;
    u8 mZoneID;                         // _20C
    u8 mType;                           // _20D
    bool mIsActive;                     // _20E
    bool mIsVisible;                    // _20F
    bool mNoSpawn;                      // _210
    u8 _211;
    u8 _212;
    u8 mEventID;                        // _213
    u8 mEventID_2;                      // _214
    u16 mActorInfoFlags;                // _215
    u8 _217;
    u32 mBumpDamageTimer;               // _218
    u32 _21C;
    u32 _220;
    u32 _224;
    u32 _228;
    u32 mKillStreak;                    // _22C
    u32 mProfileFlags;                  // _234
    Vec3 _240;
    Vec3 _24C;
    Vec3 _258;
    YoshiEatData* mYoshiEatData;        // _264
    BabyYoshiEatData* mBabyYoshiData;   // _268
    u32 _26C;
    u8* _270;
    f32 _274;
    void* mBabyYoshiBubbleData;         // _278
};