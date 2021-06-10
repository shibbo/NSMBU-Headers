#pragma once

#include "types.h"

namespace sead
{
    class ListNode
    {
    public:
        ListNode* mPrev = nullptr;
        ListNode* mNext = nullptr;
    };

    class ListImpl
    {
    public:
        ListNode mStartEnd;
        s32 mCount;
    };
};