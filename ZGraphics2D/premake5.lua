project "ZGraphics2D"
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
      "include/**.inl",
      "deps/glad/src/glad.c",
      "deps/glm/glm/detail/glm.cpp",
      "deps/stb/src/stb_image.c"
   }

   includedirs {
      "include"
   }

   sysincludedirs {
      "deps/glad/include",
      "deps/glfw/glfw/include",
      "deps/glm",
      "deps/stb/include"
   }

   links {
      "glfw3"
   }

   filter "system:windows"
      kind "StaticLib"
      systemversion "latest"
      staticruntime "on"

   filter "system:linux"
      kind "SharedLib"
      sysincludedirs {
         "/usr/include",
         "/usr/local/include"
      }
      syslibdirs {
         "/usr/lib",
         "/usr/local/lib"
      }
      links {
         "dl",
         "pthread"
      }

   filter "system:macosx"
      kind "SharedLib"
      buildoptions {
         "-Wall", "-Wextra", "-Wold-style-cast", "-Woverloaded-virtual", "-Wfloat-equal", "-Wwrite-strings",
         "-Wpointer-arith", "-Wcast-qual", "-Wcast-align", "-Wconversion", "-Wshadow", "-Wredundant-decls",
         "-Wdouble-promotion", "-Winit-self", "-Wswitch-default", "-Wswitch-enum", "-Wundef", "-Winline",
         "-fPIC", "-m64", "-fexceptions", "-pedantic"
      }
      linkoptions {
         "-fPIC", "-shared", "-lc", "-m64"
      }
      links {
         "Cocoa.framework",
         "OpenGL.framework",
         "IOKit.framework"
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
