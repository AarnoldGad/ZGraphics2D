#include "zgraphics2D/Engine/GraphicsEngine.hpp"

#include "zgraphics2D/Engine/Event/RenderEvent.hpp"

#include <zengine/Memory/New.hpp>

#define GRAPHICSWRITER_FILENAME "zgraphics.log"
#define GRAPHICSLOGGER_NAME "ZGraphics"

namespace zg
{
   bool GraphicsEngine::s_isGLFWInitialised = false;
   bool GraphicsEngine::s_isOpenGLLoaded = false;

   ze::DebugFileWriter GraphicsEngine::s_gfxWriter(GRAPHICSWRITER_FILENAME);
   ze::Logger GraphicsEngine::s_gfxLogger(GRAPHICSLOGGER_NAME);

   GraphicsEngine::GraphicsEngine(GraphicsSettings settings)
      : m_isInitialised(false), m_settings(settings) {}

   void GraphicsEngine::initialise()
   {
      if (m_isInitialised)
      {
         ZE_LOG_ERROR("Graphics Engine already initialised !");
         return;
      }

      // Init logger
      s_gfxLogger.setWriter(&s_gfxWriter);

      InitGLFW();
      openWindow();
      LoadOpenGL();

      m_isInitialised = true;
   }

   void GraphicsEngine::InitGLFW()
   {
      if (s_isGLFWInitialised) return;

      ze::Chrono loadTime;

      glfwSetErrorCallback(&GraphicsEngine::HandleGLFWError);

      GFX_LOG_INFO("------ * Initialising GLFW");
      GFX_LOG_DEBUG("------    * GLFW Compiled against %d.%d.%d", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION);
      int major, minor, rev;
      glfwGetVersion(&major, &minor, &rev);
      GFX_LOG_DEBUG("------    * GLFW Linked against %d.%d.%d", major, minor, rev);

      if (!glfwInit())
      {
         GFX_LOG_CRITICAL("------ * Fail to initialise GLFW !");
         exit(-1); // TODO Error handling
      }

      GFX_LOG_INFO("------ * GLFW initialised in %d us.", loadTime.elapsed().asMicroseconds());

      s_isGLFWInitialised = true;
   }

   void GraphicsEngine::LoadOpenGL()
   {
      if (s_isOpenGLLoaded) return;

      ze::Chrono loadTime;

      GFX_LOG_INFO("------ * Loading OpenGL...");

      if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
      {
         // TODO Error handling
         GFX_LOG_CRITICAL("------ * Fail to load OpenGL");
         exit(-1);
      }

      GFX_LOG_DEBUG("------    * OpenGL   %s", glGetString(GL_VERSION));
      GFX_LOG_DEBUG("------    * Vendor   %s", glGetString(GL_VENDOR));
      GFX_LOG_DEBUG("------    * Graphics %s", glGetString(GL_RENDERER));
      GFX_LOG_DEBUG("------    * GLSL     %s", glGetString(GL_SHADING_LANGUAGE_VERSION));

      GFX_LOG_INFO("------ * OpenGL loaded in %d us.", loadTime.elapsed().asMicroseconds());

      s_isOpenGLLoaded = true;
   }

   void GraphicsEngine::openWindow()
   {
      m_window.configure(m_settings.window, m_settings.context, m_settings.framebuffer);
      m_window.make(m_settings.title, m_settings.size, m_settings.pos, m_settings.color, m_settings.clearMask);
      m_keyboard.setWindow(&m_window);
      m_mouse.setWindow(&m_window);
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
