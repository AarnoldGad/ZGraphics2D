// Platform detection
#if defined(_WIN32) // Windows

   //#if defined(_WIN64)
      #define ZG_PLATFORM_WINDOWS
   //#else
      //#error "32-bit platforms not supported !"
   //#endif

#ifdef _MSC_VER
   #pragma warning(disable: 4251)
#endif

#elif defined(__ANDROID__) // Android
   
   #define ZG_PLATFORM_ANDROID
   #error "Android platform not supported !"

#elif defined(__linux__) // Linux

   #if defined(__x86_64__) || defined(__aarch64__)
      #define ZG_PLATFORM_LINUX
   #else
      #error "32-bit platforms not supported !"
   #endif

#elif defined(__APPLE__) || defined(__MACH__) // MacOS

   #define ZG_PLATFORM_APPLE

#else

   #error "Unsupported platform or architecture !"

#endif // Platform detection

// DLL/SO specifiers
#if __GNUC__ >= 4 || defined(__clang__)// GNU GCC __attribute__

   #define ZG_API __attribute__ ((__visibility__("default")))

#else // idk

   #define ZG_API

#endif // DLL/SO specifiers
