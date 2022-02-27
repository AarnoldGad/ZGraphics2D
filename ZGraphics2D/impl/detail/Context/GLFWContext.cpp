#include "zgpch.hpp"

#include "detail/Context/GLFWContext.hpp"

#include "zgraphics2D/Engine/GraphicsEngine.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace zg { namespace details
{
   bool ContextImpl::s_isLibInitialised = false;
   bool ContextImpl::s_isAPILoaded = false;

   void ContextImpl::Initialise()
   {
      if (s_isLibInitialised) return ze::Console::Trace("Try to initialise GLFW multiple times !");

      ze::Chrono loadTime;

      glfwSetErrorCallback(&ContextImpl::HandleGLFWError);

      GFX_LOG_INFO("------ * Initialising GLFW...");
      GFX_LOG_DEBUG("------    * GLFW Compiled against {}.{}.{}", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION);
      int major, minor, rev;
      glfwGetVersion(&major, &minor, &rev);
      GFX_LOG_DEBUG("------    * GLFW Linked against {}.{}.{}", major, minor, rev);

      if (!glfwInit())
      {
         GFX_LOG_CRITICAL("------ * Fail to initialise GLFW !");
         ze::RaiseCritical(-1, "Fail to initialise GLFW !");
      }

      GFX_LOG_INFO("------ * GLFW initialised in {} us.", loadTime.elapsed().asMicroseconds());

      s_isLibInitialised = true;
   }

   void ContextImpl::LoadAPI()
   {
      if (s_isAPILoaded) return;

      ze::Chrono loadTime;

      GFX_LOG_INFO("------ * Loading OpenGL...");

      if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
      {
         GFX_LOG_CRITICAL("------ * Fail to load OpenGL");
         ze::RaiseCritical(-1, "Fail to load OpenGL !");
      }

      GFX_LOG_DEBUG("------    * OpenGL   {}", glGetString(GL_VERSION));
      GFX_LOG_DEBUG("------    * Vendor   {}", glGetString(GL_VENDOR));
      GFX_LOG_DEBUG("------    * Graphics {}", glGetString(GL_RENDERER));
      GFX_LOG_DEBUG("------    * GLSL     {}", glGetString(GL_SHADING_LANGUAGE_VERSION));

      GFX_LOG_INFO("------ * OpenGL loaded in {} us.", loadTime.elapsed().asMicroseconds());

      s_isAPILoaded = true;
   }

   void ContextImpl::Terminate()
   {
      GFX_LOG_INFO("------ * Terminating GLFW");
      glfwTerminate();

      s_isLibInitialised = false;
   }

   void ContextImpl::HandleGLFWError(int code, char const* description)
   {
      GFX_LOG_ERROR("A GLFW Error occured : ({}) {}", code, description);
   }
}}
