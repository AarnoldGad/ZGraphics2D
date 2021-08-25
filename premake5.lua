workspace "ZucchiniGraphics"
   architecture "x86_64"
   configurations { "Debug", "Release" }
   
   sysincludedirs {
      "ZucchiniEngine/ZEngine/include"
   }
   
   syslibdirs {
      "ZucchiniEngine/ZEngine/lib"
   }
   
include "ZGraphics2D"
