#include "zgraphics2D/Engine/GraphicsEngine.hpp"

#include "zgraphics2D/Engine/RenderEvent.hpp"

#include <zengine/Core/Core.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace ze
{
   GraphicsEngine::GraphicsEngine()
      : m_isInitialised(false) {}

   void GraphicsEngine::initialise()
   {
      if (m_isInitialised)
      {
         ZE_LOG_ERROR("Graphics Engine already initialised !");
         return;
      }

      ZE_LOG_DEBUG("------ * Initialising GLFW");
      ZE_LOG_DEBUG("------     * GLFW Compiled against %d.%d.%d", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION);
      int major, minor, rev;
      glfwGetVersion(&major, &minor, &rev);
      ZE_LOG_DEBUG("------     * GLFW Linked against %d.%d.%d", major, minor, rev);

      glfwSetErrorCallback(&HandleGLFWError);

      if (!glfwInit())
         exit(-1);

      // Open Window

      ZE_LOG_DEBUG("------ * Initialising OpenGL");

      if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
      {

         exit(-1);
      }

      m_isInitialised = true;
   }

   void GraphicsEngine::tick(Time deltaTime)
   {
      RenderEvent event;
      Core::GetApplication().useEventBusTo().fireEvent(event);
   }

   void GraphicsEngine::terminate()
   {
      glfwTerminate();
   }

   GraphicsEngine::~GraphicsEngine()
   {

   }

   void HandleGLFWError(int code, char const* description)
   {
      ZE_LOG_ERROR("A GLFW Error occured : (%d) %s", code, description);
   }
}
