#pragma once

#include "types.h"
#include "sead.h"
#include "ghs/prep.h"

class BaseActor;
struct ActorBuildInfo;
struct ActorInfo;

class Profile
{
public:
    Profile(BaseActor * (*pBuildFunction)(const ActorBuildInfo *pBuildInfo), u32 id, const sead::SafeStringBase<char> &rActorName, const ActorInfo* pActorInfo, u32 flags);

    static Profile* get(u32 id);

    BaseActor* (*mBuildFunction)(const ActorBuildInfo*); // _0
    u32 mID;                                             // _4
    const ActorInfo* mActorInfo;                         // _8
    u8 mHasResourcesLoaded;                              // _C
    u8 _D;
    u16 _E;
    u32 mFlags;                                          // _10

    static u32 spriteToProfileList[];

    static const u32 NUM_PROFILES_ORIGINAL = 913;
    static const s16 prioritiesOriginal[NUM_PROFILES_ORIGINAL];
    static Profile* profilesOriginal[NUM_PROFILES_ORIGINAL];
    static u8 hasResourcesOriginal[NUM_PROFILES_ORIGINAL];
    static u8 resourceCountOriginal[NUM_PROFILES_ORIGINAL];
    static const sead::SafeStringBase<char>* resourceListsOriginal[NUM_PROFILES_ORIGINAL];
};

struct ProfileResources
{
    ProfileResources(s32 id, u32 count, const sead::SafeStringBase<char> resources[])
    {
        if (id >= Profile::NUM_PROFILES_ORIGINAL)
        {
            id = 0;
        }
        else if (id < 0)
        {
            return;
        }

        Profile::hasResourcesOriginal[id] = count > 0;
        Profile::resourceCountOriginal[id] = count;
        Profile::resourceListsOriginal[id] = resources;
    }
};

#define PROFILE_RESOURCES_IDENT(ident, id, ...)                                                                                 \
    const sead::SafeStringBase<char> PP_CONCAT(profileResourceFiles, ident)[] = { __VA_ARGS__ };                                          \
    const ProfileResources PP_CONCAT(profileResources, ident)(id, PP_NARG(__VA_ARGS__), PP_CONCAT(profileResourceFiles, ident))

#define PROFILE_RESOURCES(id, ...)   \
    PROFILE_RESOURCES_IDENT(__LINE__, id, __VA_ARGS__)
