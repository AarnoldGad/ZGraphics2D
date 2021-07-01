#include <zengine/Memory/New.hpp>

inline std::string zg::Mouse::GetButtonName(Button button) noexcept
{
   switch (button)
   {
      case Button::Left:
         return "Left";
      case Button::Right:
         return "Right";
      case Button::Middle:
         return "Middle";
      case Button::X1:
         return "X1";
      case Button::X2:
         return "X2";
      case Button::X3:
         return "X3";
      case Button::X4:
         return "X4";
      case Button::X5:
         return "X5";
      default:
         return "Unknown";
   }
}

inline bool zg::Mouse::isButtonPressed(Button button) const noexcept
{
   if (!m_window) return false;

   return static_cast<bool>(glfwGetMouseButton(m_window->getHandle(), static_cast<int>(button)));
}

inline glm::ivec2 zg::Mouse::getPosition() const noexcept
{
   if (!m_window) return { 0,0 };

   double x, y;
   glfwGetCursorPos(m_window->getHandle(), &x, &y);
   return { glm::floor(x), glm::floor(y) };
}

inline zg::Window* zg::Mouse::getWindow() noexcept
{
   return m_window;
}

template<typename EventType, typename... Args>
void zg::Mouse::PushMouseEvent(GLFWwindow* window, Args&&... args)
{
   Window* windowPtr = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));

   double x, y;
   glfwGetCursorPos(window, &x, &y);
   glm::ivec2 pos = { glm::floor(x), glm::floor(y) };

   ze::Core::GetApplication().useEventBusTo().pushEvent<EventType>(windowPtr, pos, std::forward<Args>(args)...);
}

#include <zengine/Memory/NewOff.hpp>
