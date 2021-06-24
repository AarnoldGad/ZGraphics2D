#include "zengine/Memory/New.hpp"

inline std::string zg::Window::getName() const noexcept
{
   return m_name;
}

inline std::tuple<size_t, size_t> zg::Window::getSize() const noexcept
{
   int w, h;
   glfwGetWindowSize(m_handle, &w, &h);
   return {static_cast<size_t>(w), static_cast<size_t>(h)};
}

inline std::tuple<size_t, size_t> zg::Window::getPosition() const noexcept
{
   int x, y;
   glfwGetWindowPos(m_handle, &x, &y);
   return { static_cast<size_t>(x), static_cast<size_t>(y) };
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

inline uint32_t zg::Window::getClearMask() const noexcept
{
   return m_clearMask;
}

inline GLFWwindow* zg::Window::getHandle() const noexcept
{
   return m_handle;
}

#include "zengine/Memory/NewOff.hpp"