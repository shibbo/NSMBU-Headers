#pragma once

#include "types.h"
#include "sead.h"

#include <nsmb/actor/ActorBuildInfo.h>
#include <nsmb/actor/ActorInfo.h>
#include <nsmb/profile/Profile.h>

enum PreResult
{
    TryNextFrame = 0,
    OK = 1
};

enum DoResult
{
    TryNextFrame = 0,
    Done = 1,
    Delete = 2
};

enum PostArg
{
    PrePaused = 0,
    Failed = 1,
    Succeded = 2,
    Paused = 3
};

class BaseActor
{
    SEAD_RTTI_BASE(BaseActor)
public:
    BaseActor(const ActorBuildInfo *pBuildInfo);

    virtual ~BaseActor();

    virtual PreResult beforeCreate();
    virtual DoResult onCreate();
    virtual void afterCreate(PostArg);

    virtual PreResult beforeExecute();
    virtual DoResult onExecute();
    virtual void afterExecute(PostArg);
    virtual void finalExecute();

    virtual PreResult beforeDraw();
    virtual DoResult onDraw();
    virtual void afterDraw(PostArg);

    virtual PreResult beforeDelete();
    virtual DoResult onDelete();
    virtual void afterDelete(PostArg);

    sead::Heap* mHeap; // _0
    u32 mID; // _4
    Profile* mProfile; // _8
    bool mIsNotDeffered; // _C
    bool mIsSprite; // _D
    bool mIsCreated; // _E
    bool mIsDeleted; // _F
    u32 mSettings_1; // _10
    u32 mSettings_2; // _14
    u8 mMovementID; // _18
    u8 mLinkID; // _19
    u8 mInitialStateFlags; // _1A
    u8 _1B;
    sead::OffsetList<BaseActor> mChildList; // _1C
    sead::ListNode mChildNode; // _2C
    BaseActor* mParent; // _34
    sead::ListNode mActorListNode; // _38
    sead::ListNode mDrawListNode; // _40
    u32 mFlags; // _48
};