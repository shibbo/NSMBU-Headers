#pragma once

namespace sead
{
    template<typename T>
    class SafeStringBase
    {
    public:
        SafeStringBase() : mStringTop(&cNullChar) { }

        virtual ~SafeStringBase();
        virtual void assureTerminationImpl_() const;

        inline const T* cstr() const 
        {
            assureTerminationImpl_();
            return mStringTop;
        }
        
        static const T cNullChar;

        const T* mStringTop; // _4
    };
};
