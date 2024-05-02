#pragma once
#include <memory>

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

#define BIND_EVENT_FN(x) [this](auto& event) {return x(event);}

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

namespace Thrylos
{
     template<typename T>
     using Scope = std::unique_ptr<T>;

     template<typename T>
     using Ref = std::shared_ptr<T>;

     template <typename T, typename ... Args>
     constexpr Scope<T> createScope(Args&& ... args)
     {
          return std::make_unique<T>(std::forward<Args>(args)...);
     }

     template <typename T, typename ... Args>
     constexpr Ref<T> createRef(Args&& ... args)
     {
          return std::make_shared<T>(std::forward<Args>(args)...);
     }
     
}
