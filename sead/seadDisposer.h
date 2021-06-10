#pragma once

#include <sead/seadListImpl.h>

namespace sead
{
    class Heap;

    class IDisposer
    {
    public:
        IDisposer();

        Heap* mDisposerHeap; // _0
        ListNode mListNode; // _4
    };
};