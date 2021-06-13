#pragma once

#define PP_CONCAT(x, y) x##y

#define PP_STR(x) #x

#define PP_STR_VAL(x) PP_STR(x)

#define PP_RSEQ                             \
    64, 63, 62, 61, 60, 59, 58, 57, 56, 55, \
    54, 53, 52, 51, 50, 49, 48, 47, 46, 45, \
    44, 43, 42, 41, 40, 39, 38, 37, 36, 35, \
    34, 33, 32, 31, 30, 29, 28, 27, 26, 25, \
    24, 23, 22, 21, 20, 19, 18, 17, 16, 15, \
    14, 13, 12, 11, 10,  9,  8,  7,  6,  5, \
     4,  3,  2,  1,  0

#define PP_NARG(...) \
    PP_NARG_(0, ## __VA_ARGS__, PP_RSEQ)