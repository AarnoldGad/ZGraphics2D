workspace "ZucchiniGraphics"
   architecture "x86_64"
   configurations { "Debug", "Release" }

   sysincludedirs {
      "ZucchiniEngine/ZEngineAPI/include"
   }

   syslibdirs {
      "ZucchiniEngine/lib"
   }

   filter "system:linux or macosx"
      sysincludedirs {
         "/usr/include",
         "/usr/local/include"
      }
      syslibdirs {
         "/usr/lib",
         "/usr/local/lib"
      }

   filter "configurations:Debug"
      defines "_DEBUG"
      runtime "Debug"
      symbols "on"

   filter "configurations:Release"
      defines "NDEBUG"
      runtime "Release"
      optimize "on"

include "ZGraphics2D/deps/glfw"
include "ZGraphics2D"
