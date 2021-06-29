#include <zengine/Memory/New.hpp>

inline int zg::Keyboard::GetKeyScancode(Key key) noexcept
{
   return glfwGetKeyScancode(static_cast<int>(key));
}

inline bool zg::Keyboard::isKeyPressed(Key key) noexcept
{
   if (!m_window) return false;

   return static_cast<bool>(glfwGetKey(m_window->getHandle(), static_cast<int>(key)));
}

template<typename EventType>
inline void zg::Keyboard::PushKeyEvent(GLFWwindow* window, int key, int scancode, int modifiers)
{
   Window* windowPtr = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
   ::ze::Core::GetApplication().useEventBusTo().pushEvent<EventType>(*windowPtr, static_cast<Key>(key), scancode, static_cast<uint32_t>(modifiers));
}

#include <zengine/Memory/NewOff.hpp>