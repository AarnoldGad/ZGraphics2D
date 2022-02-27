template<typename EventType, typename... Args>
inline void zg::details::MouseImpl::PushMouseEvent(GLFWwindow* window, Args&&... args)
{
   double x, y;
   glfwGetCursorPos(window, &x, &y);
   glm::ivec2 pos = { glm::floor(x), glm::floor(y) };

   Window* windowPtr = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
   ze::Core::UseEventBus().pushEvent<EventType>(windowPtr, pos, std::forward<Args>(args)...);
}

