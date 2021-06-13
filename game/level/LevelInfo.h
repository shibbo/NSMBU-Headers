#pragma once

#include "types.h"
#include "sead.h"

class LevelInfo : public sead::IDisposer
{
public:
    LevelInfo();

    virtual ~LevelInfo();

    void reset();
    void setDestWorld(u8);
    void setDestLevel(u8);
    void setDestArea(u8);
    void setDestEntrance(u8);
    void setDestEntranceType(u32);
    void goToDestLevel();
    void goToMainEntrance();

    // custom function
    void goTo(u8 worldNo, u8 levelNo, u8 areaNo, u8 entranceNo, u32 entranceType)
    {
        this->setDestWorld(worldNo);
        this->setDestLevel(levelNo);
        this->setDestArea(areaNo);
        this->setDestEntrance(entranceNo);
        this->setDestEntranceType(entranceType);
    }

    static void createInstance(sead::Heap *);
    static LevelInfo* sInstance;

    u8 mWorldNumber;                // _10
    u8 mLevelNumber;                // _11
    u8 mCurrentAreaID;              // _12
    u8 mCurrentEntranceID;          // _13
    u8 mCurrentZoneID;              // _14
    u8 _15;
    u8 _16;
    u8 _17;
    u32 mEntranceKind;              // _18
    u8 mDestinationWorld;           // _1C
    u8 mDestinationLevel;           // _1D
    u8 mDestinationArea;            // _1E
    u8 mDestinationEntrance;        // _1F
    u32 mDestinationEntranceType;   // _20
};