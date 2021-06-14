#pragma once

#include "sead/seadListImpl.h"

namespace sead
{
    template<typename T>
    class OffsetList : public ListImpl
    {
    public:
        s32 mOffs;
    };
};
