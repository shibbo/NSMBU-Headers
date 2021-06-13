#pragma once

#include "game/actor/PhysicsActor.h"
#include "game/State.h"
#include "sead.h"

class StateActor : public PhysicsActor
{
    SEAD_RTTI_OVERRIDE(StateActor, PhysicsActor)
public:
    StateActor(const ActorBuildInfo *pInfo);

    virtual ~StateActor();

    // since StateActor and MultiStateActor were compiled in the same unit,
    // we can just define the functions
    virtual void setPlayerId(s8 playerID)
    {
        this->mPlayerID = playerID;
    }

    virtual ActorPhysicsMgr* getActorPhysicsMgr() const
    {
        return *mPhysicsMgr;
    }

    virtual void vfAC() { }

    virtual u32 vfB4()
    {
        return 1;
    }

    virtual void vfBC() { }
    virtual void vfC4() { }
    virtual void vfCC() { }

    virtual void damageFromUnder() { }
    virtual void vf10C(u8 unk)
    {
        this->_179A = unk;
    }

    virtual void vf11C() { }
    virtual void vf124(f32) { }
    virtual u32 vf12C()
    {
        return 0;
    }

    virtual bool vf154()
    {
        return 0;
    }

    virtual void move(Vec2 *pNewPos)
    {
        this->mPosition.x = pNewPos->x;
        this->mPosition.y = pNewPos->y;
    }

    virtual void setYSpeed(f32 speed)
    {
        this->mSpeed.y = speed;
    }

    virtual u32 vf16C()
    {
        return 1;
    }

    virtual u32 vf174();
    {
        return 0;
    }

    virtual void getRect(Rect *pOutRect)
    {
        // this function is the exact same as PhysicsActor
        PhysicsActor::getRect(pOutRect);
    }

    StateWrapper<StateActor> mState; // _17A0
};