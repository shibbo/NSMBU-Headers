#pragma once

#include "sead.h"

class StageActor;

class HitboxCollider : public sead::IDisposer
{
public:
    typedef void (*Callback)(HitboxCollider* hcSelf, HitboxCollider* hcOther);

    enum HitboxShape
    {
        Rectangle =         0,
        Circle =            1,
        TrapezoidVert =     2,
        TrapezoidHoriz =    3
    };

    struct Info
    {
        static Info DefaultInfo;

        Vec2 mDistToCenter;     // _0
        Vec2 mDistToEdge;       // _8
        HitboxShape mShape;     // _10
        u32 _14;
        u32 _18;
        u32 _1C;
        u32 mCollisionMask;     // _20
        u32 _24;
        Callback mCallback;     // _28
    };

    class List
    {
    public:
        struct Node
        {
            HitboxCollider* mOwner; // _0
            Node* mNext;            // _4
            Node* mPrev;            // _8
        };

        

        Node* mFirst;   // _0
        Node* mLast;    // _4
    };

    HitboxCollider();

    virtual ~HitboxCollider();

    void init(StageActor *pOwner, HitboxCollider::Info *pInfo, void **pCallbackTable);
    void init(StageActor *pOwner, HitboxCollider::Info *pInfo, void **pCallbackTable, u8 *pCollisionMask);
    void init(StageActor *pOwner, HitboxCollider::Info *pInfo, void **pCallbackTable, u8 *pCollisionMask, u8 *pLayer);
    void moveToOnlyCreate(u32);
    void moveToOnlyCreateFromMask(u32);
    bool checkBit(u32) const;
    f32 getTopY() const;
    f32 getBottomY() const;
    f32 getCenterY() const;
    f32 getRightX() const;
    f32 getLeftX() const;
    f32 getCenterX() const;

    List::Node mActiveNode;     // _10
    List::Node mCreateNode;     // _1C
    List::Node _28;
    List::Node _34;
    StageActor* mOwner;         // _40
    u32 _44;
    u32 _48;
    Vec2 _4C;
    Vec2 _54;
    u32 _5C;
    u32 _60;
    u32 _64;
    u32 _68;
    u8 mCollisionMask;          // _6C
    u8 mLayer;                  // _6D
    u8 mFlags;                  // _6E
    u8 _6F;
    void** mCallbackTable;      // _70
    Info mColliderInfo;         // _74
    f32 mTrapezoidTopLeft;      // _A0
    f32 mTrapezoidTopRight;     // _A4
    f32 mTrapezoidBottomLeft;   // _A8
    f32 mTrapezoidBottomRight;  // _AC
    f32 _B0[0xF];
    f32 _EC[0xF];
};

class HitboxColliderMgr : public sead::IDisposer
{
public:
    // ctor is inlined in HitboxCollider::createInstance
    inline HitboxColliderMgr();

    virtual ~HitboxColliderMgr();

    static void createInstance(sead::Heap *);

    void removeFromActiveList(HitboxCollider *);
    void removeFromCreateList(HitboxCollider *);
    void removeFromList3(HitboxCollider *);

    HitboxCollider::List mActiveList; // _10
    HitboxCollider::List mCreateList; // _1C
    HitboxCollider::List _28;
    HitboxCollider::List _34;

    static HitboxColliderMgr* sInstance;
};