#pragma once

#ifdef THRYLOS_PLATFORM_WINDOWS
     #ifdef THRYLOS_BUILD_DLL
          #define THRYLOS_API _declspec(dllexport)
     #else
          #define THRYLOS_API _declspec(dllimport)
     #endif
#endif
