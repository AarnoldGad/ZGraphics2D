#include "zgpch.hpp"

#include "zgraphics2D/Engine/GraphicsEngine.hpp"

namespace zg
{
   bool GraphicsEngine::s_isGLFWInitialised = false;
   bool GraphicsEngine::s_isOpenGLLoaded = false;

   ze::Logger& GraphicsEngine::UseGraphicsLogger() noexcept
   {
      static ze::DebugFileWriter writer("zgraphics.log");
      static ze::Logger logger("ZGraphics", &writer);

      return logger;
   }

   GraphicsEngine::GraphicsEngine(GraphicsSettings settings)
      : m_isInitialised(false), m_settings(settings) {}

   void GraphicsEngine::initialise()
   {
      if (m_isInitialised)
      {
         ZE_LOG_ERROR("Graphics Engine already initialised !");
         return;
      }

      InitGLFW();
      openWindow();
      LoadOpenGL();
      
      glm::ivec2 fbsize = m_window.getFramebufferSize();
      glViewport(0, 0, fbsize.x, fbsize.y);

      m_isInitialised = true;
   }

   void GraphicsEngine::InitGLFW()
   {
      if (s_isGLFWInitialised) return;

      ze::Chrono loadTime;

      glfwSetErrorCallback(&GraphicsEngine::HandleGLFWError);

      GFX_LOG_INFO("------ * Initialising GLFW...");
      GFX_LOG_DEBUG("------    * GLFW Compiled against %d.%d.%d", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION);
      int major, minor, rev;
      glfwGetVersion(&major, &minor, &rev);
      GFX_LOG_DEBUG("------    * GLFW Linked against %d.%d.%d", major, minor, rev);

      if (!glfwInit())
      {
         GFX_LOG_CRITICAL("------ * Fail to initialise GLFW !");
         ze::RaiseCritical(-1, "Fail to initialise GLFW !");
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
         GFX_LOG_CRITICAL("------ * Fail to load OpenGL");
         ze::RaiseCritical(-1, "Fail to load OpenGL !");
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
      
      Keyboard::ConnectWindow(&m_window);
      Mouse::ConnectWindow(&m_window);
   }

   void GraphicsEngine::tick([[maybe_unused]] ze::Time deltaTime)
   {
      m_window.clear();

      renderingSignal.emit();

      m_window.draw();

      Keyboard::SetActiveWindow(&m_window);
      Mouse::SetActiveWindow(&m_window);
      glfwPollEvents();
   }

   void GraphicsEngine::terminate()
   {
      GFX_LOG_INFO("------ * Terminating GLFW");
      glfwTerminate();
      
      m_isInitialised = false;
   }

   GraphicsEngine::~GraphicsEngine()
   {

   }

   void GraphicsEngine::HandleGLFWError(int code, char const* description)
   {
      GFX_LOG_ERROR("A GLFW Error occured : (%d) %s", code, description);
   }
}
