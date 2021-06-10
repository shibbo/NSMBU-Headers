#pragma once

typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned int        u32;
typedef unsigned long long  u64;

typedef signed char         s8;
typedef signed short        s16;
typedef signed int          s32;
typedef signed long long    s64;

typedef float               f32;
typedef double              f64;

struct Vec2i
{
    u32 x;
    u32 y;
};

struct Vec3u
{
    u32 x;
    u32 y;
    u32 z;
};

struct Vec3i
{
    s32 x;
    s32 y;
    s32 z;
};

struct Vec2
{
    f32 x;
    f32 y;
};

struct Vec3
{
    f32 x;
    f32 y;
    f32 z;
};

struct Rect
{
    f32 x;
    f32 y;
    f32 w;
    f32 h;
};