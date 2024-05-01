#pragma once

#ifdef THRYLOS_PLATFORM_WINDOWS
     #ifdef THRYLOS_DYNAMIC_LINK
          #ifdef THRYLOS_BUILD_DLL
               #define THRYLOS_API _declspec(dllexport)
          #else
               #define THRYLOS_API _declspec(dllimport)
          #endif
     #else
          #define THRYLOS_API
     #endif
#endif

#define BIT(x) (1 << (x))

#ifdef THRYLOS_DEBUG
     #define THRYLOS_ENABLE_ASSERTS
#endif

#ifdef THRYLOS_ENABLE_ASSERTS
     #define THRYLOS_ASSERT(x, ...) { if(!(x)) { LOG_CLIENT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
     #define THRYLOS_CORE_ASSERT(x, ...) { if(!(x)) { LOG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
     #define THRYLOS_ASSERT(x, ...)
     #define THRYLOS_CORE_ASSERT(x, ...)
#endif