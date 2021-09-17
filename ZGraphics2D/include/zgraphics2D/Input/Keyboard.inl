#include <zengine/Memory/New.hpp>

inline std::string zg::Keyboard::GetKeyName(Key key) noexcept
{
   char const* name = glfwGetKeyName(static_cast<int>(key), GetKeyScancode(key));
   return name ? name : "";
}

inline int zg::Keyboard::GetKeyScancode(Key key) noexcept
{
   return glfwGetKeyScancode(static_cast<int>(key));
}

inline bool zg::Keyboard::IsKeyPressed(Key key) noexcept
{
   if (!s_window) return false;

   return static_cast<bool>(glfwGetKey(s_window->getHandle(), static_cast<int>(key)));
}

inline void zg::Keyboard::SetActiveWindow(Window* window) noexcept
{
   s_window = window;
}

inline zg::Window* zg::Keyboard::GetWindow() noexcept
{
   return s_window;
}

template<typename EventType>
inline void zg::Keyboard::PushKeyEvent(GLFWwindow* window, int key, int scancode, int modifiers)
{
   Window* windowPtr = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
   ::ze::Core::UseEventBus().pushEvent<EventType>(windowPtr, static_cast<Key>(key), scancode, static_cast<uint32_t>(modifiers));
}

#include <zengine/Memory/NewOff.hpp>
