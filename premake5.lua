workspace "ZucchiniGraphics"
   architecture "x86_64"
   configurations { "Debug", "Release" }
   
   includedirs {
      "ZucchiniEngine/ZEngine/include"
   }
   
   libdirs {
      "ZucchiniEngine/ZEngine/lib"
   }
   
include "ZGraphics2D"
