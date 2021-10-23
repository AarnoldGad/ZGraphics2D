inline std::string zg::Window::getTitle() const noexcept
{
   return m_title;
}

inline glm::ivec2 zg::Window::getSize() const noexcept
{
   int width, height;
   glfwGetWindowSize(m_handle, &width, &height);
   return { width, height };
}

inline glm::ivec2 zg::Window::getFramebufferSize() const noexcept
{
   int width, height;
   glfwGetFramebufferSize(m_handle, &width, &height);
   return { width, height };
}

inline glm::ivec2 zg::Window::getPosition() const noexcept
{
   int x, y;
   glfwGetWindowPos(m_handle, &x, &y);
   return { x, y };
}

inline float zg::Window::getOpacity() const noexcept
{
   return glfwGetWindowOpacity(m_handle);
}

inline bool zg::Window::isVisible() const noexcept
{
   return static_cast<bool>(glfwGetWindowAttrib(m_handle, GLFW_VISIBLE));
}

inline bool zg::Window::shouldClose() const noexcept
{
   return static_cast<bool>(glfwWindowShouldClose(m_handle));
}

inline glm::vec4 zg::Window::getColor() const noexcept
{
   return m_color;
}

inline uint32_t zg::Window::getClearMask() const noexcept
{
   return m_clearMask;
}

inline GLFWwindow* zg::Window::getHandle() noexcept
{
   return m_handle;
}

template<typename EventType, typename... Args>
inline void zg::Window::PushWindowEvent(GLFWwindow* window, Args&&... args)
{
   Window* windowPtr = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
   ::ze::Core::UseEventBus().pushEvent<EventType>(windowPtr, std::forward<Args>(args)...);
}
