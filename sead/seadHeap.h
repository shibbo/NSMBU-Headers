#pragma once

#include <sead/seadDisposer.h>
#include <sead/seadNamable.h>
#include <sead/seadHostIO.h>

namespace sead
{
    class Heap : public IDisposer, public INamable, public hostio::Reflexible
    {
    public:
        // do we realy have to care about this in most instances?
    };
};