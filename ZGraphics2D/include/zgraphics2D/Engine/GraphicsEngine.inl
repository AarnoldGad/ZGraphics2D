#include <zengine/Memory/New.hpp>

inline ze::Logger& zg::GraphicsEngine::UseGraphicsLogger() noexcept
{
   zassert(s_gfxLogger.getWriter() != nullptr, "Graphics logger not initialised"); // TODO Error handling
   return s_gfxLogger;
}

#include <zengine/Memory/NewOff.hpp>