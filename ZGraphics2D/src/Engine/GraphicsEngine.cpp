#include "zgpch.hpp"

#include "zgraphics2D/Engine/GraphicsEngine.hpp"

#include "zgraphics2D/Engine/Context.hpp"

namespace zg
{
   ze::Logger& GraphicsEngine::UseGraphicsLogger() noexcept
   {
      static ze::FileWriter writer("zgraphics.log");
      static ze::Logger logger("ZGraphics", { &writer, &ze::ConsoleWriter::Get() });

      return logger;
   }

   GraphicsEngine::GraphicsEngine(GraphicsSettings settings)
      : m_isInitialised(false), m_settings(settings) {}

   void GraphicsEngine::initialise()
   {
      if (m_isInitialised)
      {
         GFX_LOG_ERROR("Graphics Engine already initialised !");
         return;
      }

      Context::Initialise();
      openWindow();
      Context::LoadAPI();

      glm::ivec2 fbsize = m_window->getFramebufferSize();
      glViewport(0, 0, fbsize.x, fbsize.y);

      m_isInitialised = true;
   }

   void GraphicsEngine::openWindow()
   {
      Window::Configure(m_settings.window, m_settings.context, m_settings.framebuffer);
      m_window = Window::Make(m_settings.title, m_settings.size, m_settings.pos);

      m_window->setColor(m_settings.color);
   }

   void GraphicsEngine::tick([[maybe_unused]] ze::Time deltaTime)
   {
      Context::SetActiveContext(m_window.get());
      m_window->clear();

      renderingSignal.emit();

      m_window->draw();

      Context::PollEvents();
   }

   void GraphicsEngine::terminate()
   {
      Context::Terminate();

      m_isInitialised = false;
   }

   GraphicsEngine::~GraphicsEngine()
   {

   }
}
