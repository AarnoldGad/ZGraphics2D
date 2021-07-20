#include "zgraphics2D/Engine/GraphicApplication.hpp"

namespace zg
{
   GraphicApplication::GraphicApplication(GraphicsEngine& engine)
      : m_engine(&engine)
   {
      m_closeSubscriber = ze::Core::GetApplication().useEventBusTo().subscribe<WindowClosedEvent>(&GraphicApplication::close, this);
   }

   void GraphicApplication::close(WindowClosedEvent& event)
   {
      if (event.getWindow() == &m_engine->getWindow())
         ze::Core::GetApplication().stop();
   }
}
