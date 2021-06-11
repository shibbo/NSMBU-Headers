#pragma once

#include <sead/seadSafeString.h>

namespace sead
{
    class INamable
    {
    public:
        INamable();

        SafeStringBase<char> mINamableName;
    };
};
