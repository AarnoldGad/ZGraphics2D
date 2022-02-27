template<typename EventType>
inline void zg::details::KeyboardImpl::PushKeyEvent(GLFWwindow* window, int key, int scancode, int modifiers)
{
   Window* windowPtr = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
   ::ze::Core::UseEventBus().pushEvent<EventType>(windowPtr, static_cast<Keyboard::Key>(key), scancode, static_cast<uint32_t>(modifiers));
}

