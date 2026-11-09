//
// Created by Brandon on 11/9/2026.
//
#pragma once
#include <string>


#if defined(_WIN32)
    #define HUNTER_WINDOWS

#elif defined(__APPLE__)
    #define HUNTER_APPLE

#elif defined(__linux__)
    #define HUNTER_LINUX

#else
    #error "Platform not supported"
#endif

namespace Platform {
    int getScreenWidth();
    void screenSize();
}
