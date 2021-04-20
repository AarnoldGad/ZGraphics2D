workspace "ZucchiniGraphics"
   architecture "x86_64"
   configurations { "Debug", "Release" }

   
project "ZGraphics2D"
   kind "SharedLib"
   language "C++"
   cppdialect "C++17"

   targetname("zgraphics2D")
   
   filter "configurations:Debug"
      targetsuffix "-d"

   filter {}

   targetdir("%{prj.location}/lib")
   objdir("%{prj.location}/bin/%{cfg.buildcfg}")

   files {
      "src/**.cpp",
      "include/**.hpp",
      "include/**.inl"
   }

   includedirs {
      "include",
      "ZEngine/include"
   }
   
   libdirs {
      "lib"
   }

   filter "system:windows"
      systemversion "latest"

   filter "system:linux"
      includedirs {
         "/usr/include",
         "/usr/local/include"
      }
      libdirs {
         "/usr/lib",
         "/usr/local/lib"
      }
      links {
         "dl",
         "pthread"
      }

   filter { "action:gmake*", "toolset:gcc" }
      buildoptions {
         "-Wall", "-Wextra", "-Wold-style-cast", "-Woverloaded-virtual", "-Wfloat-equal", "-Wwrite-strings",
         "-Wpointer-arith", "-Wcast-qual", "-Wcast-align", "-Wconversion", "-Wshadow", "-Wredundant-decls",
         "-Wdouble-promotion", "-Winit-self", "-Wswitch-default", "-Wswitch-enum", "-Wundef", "-Wlogical-op", "-Winline",
         "-fPIC", "-m64", "-fexceptions", "-pedantic"
      }
      linkoptions {
         "-fPIC", "-shared", "-lc", "-m64"
      }

   filter "configurations:Debug"
      links {
         "zengine-d"
      }
      runtime "Debug"
      symbols "On"

   filter "configurations:Release"
      links {
         "zengine"
      }
      runtime "Release"
      optimize "On"
