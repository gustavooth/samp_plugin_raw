#pragma once

// Unsigned int types.
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

// Signed int types.
typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

// Floating point types
typedef float f32;
typedef double f64;

// Boolean types
typedef char b8;

#define true 1
#define false 0

// Platform detection
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
  #define PLATFORM_WINDOWS 1
#elif defined(__linux__) || defined(__gnu_linux__)
  #define PLATFORM_LINUX 1
#endif

#if defined(_MSC_VER)
  #define PACKED __pragma(pack(push, 1))
  #define UNPACKED __pragma(pack(pop))
#else
  #define PACKED __attribute__((packed))
  #define UNPACKED
#endif

#ifdef PLUGIN_EXPORT
  // Exports
  #ifdef _MSC_VER
    #define PLUGINAPI __declspec(dllexport)
  #else
    #define PLUGINAPI __attribute__((visibility("default")))
  #endif // _MSC_VER

#else
  // Imports
  #ifdef _MSC_VER
    #define PLUGINAPI __declspec(dllimport)
  #else
    #define PLUGINAPI
  #endif
#endif

