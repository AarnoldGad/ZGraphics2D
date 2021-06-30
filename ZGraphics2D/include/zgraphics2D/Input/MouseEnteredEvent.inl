#include <zengine/Memory/New.hpp>

inline bool zg::MouseEnteredEvent::hasEntered() const noexcept
{
   return m_entered;
}

inline bool zg::MouseEnteredEvent::hasLeaved() const noexcept
{
   return !m_entered;
}

#include <zengine/Memory/NewOff.hpp>