#pragma once

#include "game/actor/PhysicsActor.h"
#include "game/State.h"
#include "sead.h"

class MultiStateActor : public PhysicsActor
{
    SEAD_RTTI_OVERRIDE(MultiStateActor, PhysicsActor)
public:
    MultiStateActor(const ActorBuildInfo *pBuildInfo);

    virtual ~MultiStateActor();

    virtual void setPlayerId(s8);
    virtual ActorPhysicsMgr* getActorPhysicsMgr() const;
    virtual void vfAC();
    virtual u32 vfB4();
    virtual void vfBC();
    virtual void vfC4();
    virtual void vfCC();

    virtual void damageFromUnder();
    virtual void vf10C(u8 unk);
    virtual void vf11C();
    virtual void vf124(f32);
    virtual u32 vf12C();

    virtual bool vf154();
    virtual void move(Vec2 *);
    virtual void setYSpeed(f32);
    virtual u32 vf16C();
    virtual u32 vf174();
    virtual void getRect(Rect *);
    virtual void doStateChange(StateBase *);

    StateWrapperMulti<MultiStateActor> mStates;  // _17A0
};
