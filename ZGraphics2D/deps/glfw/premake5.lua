project "glfw3"
   kind "StaticLib"
   language "C"

   targetdir("%{prj.location}/lib")
   objdir("%{prj.location}/bin/%{cfg.buildcfg}")

   files {
		"glfw/include/GLFW/glfw3.h",
		"glfw/include/GLFW/glfw3native.h",
      "glfw/src/glfw_config.h",
		"glfw/src/context.c",
		"glfw/src/init.c",
		"glfw/src/input.c",
		"glfw/src/monitor.c",
		"glfw/src/vulkan.c",
		"glfw/src/window.c"
	}

   filter "system:windows"
      systemversion "latest"
      staticruntime "on"
      files {
         "glfw/src/win32_init.c",
			"glfw/src/win32_joystick.c",
			"glfw/src/win32_monitor.c",
			"glfw/src/win32_time.c",
			"glfw/src/win32_thread.c",
			"glfw/src/win32_window.c",
			"glfw/src/wgl_context.c",
			"glfw/src/egl_context.c",
			"glfw/src/osmesa_context.c"
      }
      defines {
         "_GLFW_WIN32"
      }

   filter "system:linux"
      pic "on"
      staticruntime "on"
      sysincludedirs {
         "/usr/include",
         "/usr/local/include"
      }
      syslibdirs {
         "/usr/lib",
         "/usr/local/lib"
      }
      files {
         "glfw/src/x11_init.c",
			"glfw/src/x11_monitor.c",
			"glfw/src/x11_window.c",
			"glfw/src/xkb_unicode.c",
			"glfw/src/posix_time.c",
			"glfw/src/posix_thread.c",
			"glfw/src/glx_context.c",
			"glfw/src/egl_context.c",
			"glfw/src/osmesa_context.c",
			"glfw/src/linux_joystick.c"
      }
      defines {
         "_GLFW_X11"
      }

   filter "system:macosx"
      pic "on"
      staticruntime "on"
      files {
         "glfw/cocoa_init.m",
         "glfw/cocoa_joystick.m",
         "glfw/cocoa_monitor.m",
         "glfw/cocoa_window.m",
         "glfw/cocoa_time.c",
         "glfw/posix_thread.c",
         "glfw/nsgl_context.m",
         "glfw/egl_context.c",
         "glfw/osmesa_context.c"
      }
      defines {
         "_GLFW_COCOA"
      }

   filter "configurations:Debug"
      runtime "Debug"
      symbols "On"

   filter "configurations:Release"
      runtime "Release"
      optimize "On"
