#pragma once

#include "game/actor/MultiStateActor.h"
#include "game/enemy/EnemyFreezeMgr.h"
#include "game/State.h"
#include "sead.h"

class SomeEnemyClass
{
public:
    void copyTo(SomeEnemyClass *);
    
    f32 _0;
    f32 _4;
    f32 _8;
    f32 _C;
    u32 _10;
    u8 _14;
    u8 _15;     // _21C from StageActor
    u8 _16;
    u8 _17;
    u8 _18;
};

class Enemy : public MultiStateActor
{
    SEAD_RTTI_OVERRIDE(Enemy, MultiStateActor)
public:
    Enemy(const ActorBuildInfo *pBuildInfo);

    virtual ~Enemy();

    virtual u32 beforeExecute();

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

    virtual u32 vf18C();
    virtual void damagePlayer(HitboxCollider *, HitboxCollider *);
    virtual bool vf19C(s8) const;
    virtual void freeze();
    virtual void vf1AC();
    virtual void vf1B4();
    virtual void vf1BC();
    virtual void vf1C4();
    virtual u32 vf1CC();

    virtual bool vf1D4(HitboxCollider* pHCSelf, HitboxCollider* pHCOther);
    virtual bool vf1DC(HitboxCollider* pHCSelf, HitboxCollider* pHCOther);
    virtual bool vf1E4(bool& unk, HitboxCollider* pHCSelf, HitboxCollider* pHCOther);
    virtual void vf1EC(HitboxCollider* pHCSelf, HitboxCollider* pHCOther);
    virtual bool vf1F4(HitboxCollider* pHCSelf, HitboxCollider* pHCOther);
    virtual bool vf1FC(HitboxCollider* pHCSelf, HitboxCollider* pHCOther);
    virtual bool vf204(HitboxCollider* pHCSelf, HitboxCollider* pHCOther);

    virtual void collisionEnemy(HitboxCollider* pHCSelf, HitboxCollider* pHCOther);
    virtual void collisionPlayer(HitboxCollider* pHCSelf, HitboxCollider* pHCOther);
    virtual void collisionYoshi(HitboxCollider* pHCSelf, HitboxCollider* pHCOther);
    virtual void vf224(HitboxCollider* pHCSelf, HitboxCollider* pHCOther);

    virtual bool collisionStar(HitboxCollider* pHCSelf, HitboxCollider* pHCOther);
    virtual bool collisionSlide(HitboxCollider* pHCSelf, HitboxCollider* pHCOther);
    virtual bool collisionPropellerDrill(HitboxCollider* pHCSelf, HitboxCollider* pHCOther);
    virtual bool vf244(HitboxCollider* pHCSelf, HitboxCollider* pHCOther);
    virtual bool collisionGroundPound(HitboxCollider* pHCSelf, HitboxCollider* pHCOther);
    virtual bool collisionGroundPoundYoshi(HitboxCollider* pHCSelf, HitboxCollider* pHCOther);
    virtual bool collisionPenguinSlide(HitboxCollider* pHCSelf, HitboxCollider* pHCOther);
    virtual bool collisionPipeCannon(HitboxCollider* pHCSelf, HitboxCollider* pHCOther);
    virtual bool vf26C(HitboxCollider* pHCSelf, HitboxCollider* pHCOther);
    virtual bool collisionThrowableObject(HitboxCollider* pHCSelf, HitboxCollider* pHCOther);
    virtual bool collisionFireball(HitboxCollider* pHCSelf, HitboxCollider* pHCOther);
    virtual bool collisionIceball(HitboxCollider* pHCSelf, HitboxCollider* pHCOther);
    virtual bool collisionHammer(HitboxCollider* pHCSelf, HitboxCollider* pHCOther);
    virtual bool collisionFireballYoshi(HitboxCollider* pHCSelf, HitboxCollider* pHCOther);
    virtual bool vf29C(HitboxCollider* pHCSelf, HitboxCollider* pHCOther);
    virtual bool vf2A4(HitboxCollider* pHCSelf, HitboxCollider* pHCOther);
    virtual bool vf2AC(HitboxCollider* pHCSelf, HitboxCollider* pHCOther);
    virtual bool vf2B4(HitboxCollider* pHCSelf, HitboxCollider* pHCOther);
    virtual void vf2BC(HitboxCollider *, HitboxCollider *);
    virtual void vf2C4();
    virtual void vf2CC(HitboxCollider *, HitboxCollider *);
    virtual bool isOnGround() const;
    virtual void vf2DC();
    virtual void vf2E4();
    virtual void vf2EC(u32 *);
    virtual void vf2F4(u32 *);
    virtual void vf2FC(u32 *);
    virtual void vf304();
    virtual void vf30C(u32 *);
    virtual void vf314(u32 *);
    virtual void vf31C();
    virtual void vf324(u32 *);
    virtual void vf32C();
    virtual void vf334();
    virtual void vf33C(u32 *);
    virtual void vf344();
    virtual void vf34C();
    virtual void vf354();
    virtual void vf35C(u32 *);
    virtual void vf364(u32 *);
    virtual void vf36C(u32 *);
    virtual void vf374();

    // everything after this point are all states

    DECLARE_STATE_VIRTUAL(Enemy, DieFumi)  // 37C 384 38C
    DECLARE_STATE_VIRTUAL(Enemy, DieFall)  // 394 39C 3A4

    virtual void vf3AC();
    virtual void vf3B4();
    virtual void vf3BC();
    virtual void vf3C4();
    virtual void vf3CC();
    virtual void vf3D4();
    virtual void vf3DC();
    virtual void vf3E4();
    virtual void vf3EC();
    virtual void vf3F4();
    virtual void vf3FC();
    virtual void vf404();
    virtual void vf40C();
    virtual void vf414();
    virtual void vf41C();
    virtual void vf424();
    virtual void vf42C();
    virtual void vf434();
    virtual void vf43C();
    virtual void vf444();
    virtual void vf44C();
    virtual void vf454();
    virtual void vf45C();
    virtual void vf464();
    virtual void vf46C();
    virtual void vf474();
    virtual void vf47C();
    virtual void vf484();
    virtual void vf48C();
    virtual void vf494();
    virtual void vf49C();
    virtual void vf4A4();
    virtual void vf4AC();
    virtual void vf4B4();
    virtual void vf4BC();
    virtual void vf4C4();

    DECLARE_STATE_VIRTUAL(Enemy, Ice)  // 4CC 4D4 4DC 

    SomeEnemyClass _17C8;
    u16 _17E4[4];
    u32 _17EC;
    EnemyFreezeMgr mFreezeMgr; // _17F0
    u8 _1840[0x1860-0x1840];
    Enemy* mSelf; // _1860
    void* _1864;
    u8 _1868;
    u8 _1869;
    u8 _186A;
    u8 _186B;
    u16 _186C;
    u16 _186E;
    u32 _1870;
    u8 _1874;
    u8 _1875;
    u8 _1876;
    u8 _1877;
    u32 _1878;
    u8 _187C;
    u8 _187D;
    u8 _187E;
    u8 _187F;
};