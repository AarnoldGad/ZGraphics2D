inline std::string const& zg::details::WindowImpl::getTitle() const noexcept
{
   return m_title;
}

inline glm::ivec2 zg::details::WindowImpl::getSize() const noexcept
{
   int width, height;
   glfwGetWindowSize(m_handle, &width, &height);
   return { width, height };
}

inline glm::ivec2 zg::details::WindowImpl::getFramebufferSize() const noexcept
{
   int width, height;
   glfwGetFramebufferSize(m_handle, &width, &height);
   return { width, height };
}

// TODO
// inline zg::Image const& zg::details::WindowImpl::getIcon() const noexcept
// {
// 
// }

inline glm::ivec2 zg::details::WindowImpl::getPosition() const noexcept
{
   int x, y;
   glfwGetWindowPos(m_handle, &x, &y);
   return { x, y };
}

inline float zg::details::WindowImpl::getOpacity() const noexcept
{
   return glfwGetWindowOpacity(m_handle);
}

inline bool zg::details::WindowImpl::isVisible() const noexcept
{
   return static_cast<bool>(glfwGetWindowAttrib(m_handle, GLFW_VISIBLE));
}

inline bool zg::details::WindowImpl::shouldClose() const noexcept
{
   return static_cast<bool>(glfwWindowShouldClose(m_handle));
}

inline glm::vec4 zg::details::WindowImpl::getColor() const noexcept
{
   return m_color;
}

inline uint32_t zg::details::WindowImpl::getClearMask() const noexcept
{
   return m_clearMask;
}

inline void* zg::details::WindowImpl::getHandle() noexcept
{
   return static_cast<void*>(m_handle);
}

template<typename EventType, typename... Args>
inline void zg::details::WindowImpl::PushWindowEvent(GLFWwindow* window, Args&&... args)
{
   Window* windowPtr = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
   ::ze::Core::UseEventBus().pushEvent<EventType>(windowPtr, std::forward<Args>(args)...);
}
