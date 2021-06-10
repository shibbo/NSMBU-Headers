#pragma once

#include "nsmb/actor/StageActor.h"
#include "nsmb/collision/ActorPhysicsMgr.h"
#include "sead.h"

class PhysicsActor : public StageActor
{
    SEAD_RTTI_OVERRIDE(PhysicsActor, StageActor)
public:
    PhysicsActor(const ActorBuildInfo *pInfo);

    virtual ~PhysicsActor();

    virtual void afterCreate(PostArg);
    virtual PreResult beforeExecute();
    virtual void afterExecute(PostArg);
    virtual DoResult onDelete();

    virtual void setPlayerId(s8);
    virtual ActorPhysicsMgr* getActorPhysicsMgr() const;
    virtual void vfAC();
    virtual u32 vfB4();
    virtual void vfBC();
    virtual void vfC4();
    virtual void vfCC();

    virtual void updateChallengeBumpTimer();

    virtual void vf10C(u8 unk);
    virtual u8 vf114();
    virtual void vf11C();
    virtual void vf124(f32);
    virtual u32 vf12C();
    virtual void vf134();
    virtual u32 vf13C();
    virtual void vf144(bool);
    virtual void vf14C(StageActor *);

    virtual bool vf154();
    virtual void move(Vec2 *);
    virtual void setYSpeed(f32);
    virtual u32 vf16C();
    virtual u32 vf174();
    virtual void getRect(Rect *);

    u32 _27C;
    ActorPhysicsMgr mPhysicsMgr;        // _280
    f32 _1760;
    f32 _1764;
    Vec3* _1768;
    u8 _176C;
    u8 _176D;
    u8 _176E;
    u8 _176F;
    u32 _1770;
    f32 _1774;
    Vec2 _1778;
    Vec2 _1780;
    f32 mMaxYSpeed;                     // _1788
    f32 mMinYSpeed;                     // _178C
    f32 _1790;
    u8 _1794;
    u8 _1795;
    u8 _1796;
    u8 _1797;
    u8 _1798;
    u8 _1799;
    u8 _179A;
    u8 _179B; 
    u32 _179C;
};