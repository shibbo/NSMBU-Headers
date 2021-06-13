#pragma once

#include "types.h"

namespace sead
{
    class ListNode
    {
    public:
        ListNode* mPrev;
        ListNode* mNext;
    };

    class ListImpl
    {
    public:
        ListNode mStartEnd;
        s32 mCount;
    };
};
