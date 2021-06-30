#include <zengine/Memory/New.hpp>

inline zg::Mouse::Button zg::MouseButtonEvent::getButton() const noexcept
{
   return m_button;
}

inline zg::MouseButtonEvent::Action zg::MouseButtonEvent::getAction() const noexcept
{
   return m_action;
}

inline uint32_t zg::MouseButtonEvent::getModifiers() const noexcept
{
   return m_modifiers;
}

#include <zengine/Memory/NewOff.hpp>