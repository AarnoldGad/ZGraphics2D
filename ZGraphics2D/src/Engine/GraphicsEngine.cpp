#include "zgraphics2D/Engine/GraphicsEngine.hpp"

#include "zgraphics2D/Engine/RenderEvent.hpp"

#include <zengine/Memory/New.hpp>

#define GRAPHICSWRITER_FILENAME "zgraphics.log"
#define GRAPHICSLOGGER_NAME "ZGraphics"

namespace zg
{
   ze::DebugFileWriter GraphicsEngine::s_gfxWriter(GRAPHICSWRITER_FILENAME);
   ze::Logger GraphicsEngine::s_gfxLogger(GRAPHICSLOGGER_NAME);

   GraphicsEngine::GraphicsEngine()
      : m_isInitialised(false) {}

   void GraphicsEngine::initialise()
   {
      if (m_isInitialised)
      {
         ZE_LOG_ERROR("Graphics Engine already initialised !");
         return;
      }

      // Init logger
      s_gfxLogger.setWriter(&s_gfxWriter);

      GFX_LOG_INFO("------ * Initialising GLFW");
      GFX_LOG_INFO("------     * GLFW Compiled against %d.%d.%d", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION);
      int major, minor, rev;
      glfwGetVersion(&major, &minor, &rev);
      GFX_LOG_INFO("------     * GLFW Linked against %d.%d.%d", major, minor, rev);

      // Init GLFW
      glfwSetErrorCallback(&GraphicsEngine::HandleGLFWError);

      if (!glfwInit())
         exit(-1); // TODO Error handling

      // Open Window
      WindowSettings settings;
      m_window.create("Episode One", 800, 600, settings);
      m_keyboard.setWindow(&m_window);
      m_mouse.setWindow(&m_window);

      // Init OpenGL
      GFX_LOG_INFO("------ * Loading OpenGL");

      if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
      {
         // TODO Error handling
         GFX_LOG_CRITICAL("------ * Fail to load OpenGL");
         exit(-1);
      }

      m_isInitialised = true;
   }

   void GraphicsEngine::tick(ze::Time deltaTime)
   {
      m_window.clear();

      RenderEvent event;
      ze::Core::GetApplication().useEventBusTo().fireEvent(event);

      m_window.draw();

      glfwPollEvents();
   }

   void GraphicsEngine::terminate()
   {
      GFX_LOG_INFO("------ * Terminating GLFW");
      glfwTerminate(); // TODO Program exit hook (same for memory manager)
   }

   GraphicsEngine::~GraphicsEngine()
   {

   }

   void GraphicsEngine::HandleGLFWError(int code, char const* description)
   {
      GFX_LOG_ERROR("A GLFW Error occured : (%d) %s", code, description);
   }
}
