project "ZGraphics2D"
   kind "StaticLib"
   language "C++"
   cppdialect "C++20"
   staticruntime "off"

   targetname("zgraphics2D")

   filter "configurations:Debug"
      targetsuffix "-d"
   filter {}

   targetdir("%{prj.location}/../lib")
   objdir("%{prj.location}/obj/%{cfg.buildcfg}")

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
      "glfw3",
      "ZEngineAPI"
   }

   filter "system:windows"
      systemversion "latest"

   filter "system:linux"
      links {
         "dl",
         "pthread"
      }

   filter "system:macosx"
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
