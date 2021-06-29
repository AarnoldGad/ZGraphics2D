#include <zengine/Memory/New.hpp>

inline ze::Logger& zg::GraphicsEngine::UseGraphicsLogger() noexcept
{
   zassert(s_gfxLogger.getWriter() != nullptr, "Graphics logger not initialised"); // TODO Error handling
   return s_gfxLogger;
}

inline zg::Window& zg::GraphicsEngine::getMainWindow() noexcept
{
   return m_window;
}

inline zg::Keyboard& zg::GraphicsEngine::getKeyboard() noexcept
{
   return m_keyboard;
}

#include <zengine/Memory/NewOff.hpp>
