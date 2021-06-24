#include "zgraphics2D/Engine/GraphicsEngine.hpp"

#include "zgraphics2D/Engine/RenderEvent.hpp"
#include "zgraphics2D/Input/Input.hpp"

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

      s_gfxLogger.setWriter(&s_gfxWriter);

      GFX_LOG_INFO("------ * Initialising GLFW");
      GFX_LOG_INFO("------     * GLFW Compiled against %d.%d.%d", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION);
      int major, minor, rev;
      glfwGetVersion(&major, &minor, &rev);
      GFX_LOG_INFO("------     * GLFW Linked against %d.%d.%d", major, minor, rev);

      glfwSetErrorCallback(&GraphicsEngine::HandleGLFWError);

      if (!glfwInit())
         exit(-1); // TODO Error handling

      // Open Window
      m_window = glfwCreateWindow(800, 600, "titre", nullptr, nullptr);
      Input::Initialise(m_window);
      // TODO Error handling
      glfwMakeContextCurrent(m_window);

      GFX_LOG_INFO("------ * Initialising OpenGL");

      if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
      {
         // TODO Error handling
         exit(-1);
      }

      m_isInitialised = true;
   }

   void GraphicsEngine::tick(ze::Time deltaTime)
   {
      RenderEvent event;
      ze::Core::GetApplication().useEventBusTo().fireEvent(event);
   }

   void GraphicsEngine::terminate()
   {
      GFX_LOG_INFO("------ * Terminating GLFW");
      glfwTerminate();
   }

   GraphicsEngine::~GraphicsEngine()
   {

   }

   void HandleGLFWError(int code, char const* description)
   {
      GFX_LOG_ERROR("A GLFW Error occured : (%d) %s", code, description);
   }
}
