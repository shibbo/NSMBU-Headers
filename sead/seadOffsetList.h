#pragma once

#include "sead/seadListImpl.h"

namespace sead
{
    template<typename T>
    class OffsetList : public ListImpl
    {
    public:
        T* mPtr;
        ListNode* mNext;
        s32 mOffs;
    };
};
