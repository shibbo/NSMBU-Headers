#pragma once

namespace sead
{
    namespace RuntimeTypeInfo
    {
        class Interface
        {
        public:
            Interface() {}

            virtual bool isDerived(const Interface* typeInfo) const = 0;
        };

        class Root : public Interface
        {
        public:
            Root() {}

            bool isDerived(const Interface* typeInfo) const override;
        };

        
        template <typename BaseType>
        class Derive : public Interface
        {
        public:
            Derive() {}

            bool isDerived(const Interface* typeInfo) const override;
        };
  
    };
};

#define SEAD_RTTI_BASE(CLASS)                                                                      \
public:                                                                                            \
    static const sead::RuntimeTypeInfo::Interface* getRuntimeTypeInfoStatic()                      \
    {                                                                                              \
        static const sead::RuntimeTypeInfo::Root typeInfo;                                         \
        return &typeInfo;                                                                          \
    }                                                                                              \
                                                                                                   \
    static bool checkDerivedRuntimeTypeInfoStatic(                                                 \
        const sead::RuntimeTypeInfo::Interface* typeInfo)                                          \
    {                                                                                              \
        const sead::RuntimeTypeInfo::Interface* clsTypeInfo = CLASS::getRuntimeTypeInfoStatic();   \
        return typeInfo == clsTypeInfo;                                                            \
    }                                                                                              \
                                                                                                   \
    virtual bool checkDerivedRuntimeTypeInfo(const sead::RuntimeTypeInfo::Interface* typeInfo)     \
        const                                                                                      \
    {                                                                                              \
        return checkDerivedRuntimeTypeInfoStatic(typeInfo);                                        \
    }                                                                                              \
                                                                                                   \
    virtual const sead::RuntimeTypeInfo::Interface* getRuntimeTypeInfo() const                     \
    {                                                                                              \
        return getRuntimeTypeInfoStatic();                                                         \
    }

#define SEAD_RTTI_OVERRIDE(CLASS, BASE)                                                            \
public:                                                                                            \
    static const sead::RuntimeTypeInfo::Interface* getRuntimeTypeInfoStatic()                      \
    {                                                                                              \
        static const sead::RuntimeTypeInfo::Derive<BASE> typeInfo;                                 \
        return &typeInfo;                                                                          \
    }                                                                                              \
                                                                                                   \
    static bool checkDerivedRuntimeTypeInfoStatic(                                                 \
        const sead::RuntimeTypeInfo::Interface* typeInfo)                                          \
                                                                                                   \
    {                                                                                              \
        const sead::RuntimeTypeInfo::Interface* clsTypeInfo = CLASS::getRuntimeTypeInfoStatic();   \
        if (typeInfo == clsTypeInfo)                                                               \
            return true;                                                                           \
                                                                                                   \
        return BASE::checkDerivedRuntimeTypeInfoStatic(typeInfo);                                  \
    }                                                                                              \
                                                                                                   \
    bool checkDerivedRuntimeTypeInfo(const sead::RuntimeTypeInfo::Interface* typeInfo)             \
        const override                                                                             \
    {                                                                                              \
        return checkDerivedRuntimeTypeInfoStatic(typeInfo);                                        \
    }                                                                                              \
                                                                                                   \
    const sead::RuntimeTypeInfo::Interface* getRuntimeTypeInfo() const override                    \
    {                                                                                              \
        return getRuntimeTypeInfoStatic();                                                         \
    }
