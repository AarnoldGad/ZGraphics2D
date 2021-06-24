#include "zgraphics2D/Window/Window.hpp"

namespace zg
{
   Window::Window(std::string const& name, size_t width, size_t height)
      : m_name(name), m_clearMask(GL_COLOR_BUFFER_BIT), m_handle(nullptr)
   {
      m_handle = glfwCreateWindow(static_cast<int>(width), static_cast<int>(height), m_name.c_str(), nullptr, nullptr);
      if (!m_handle)
         exit(-1); // TODO Error handling

      //glfwSetWindowUserPointer(m_handle, this);
   }

   void Window::clear()
   {
      if (glfwGetCurrentContext() != getHandle())
         glfwMakeContextCurrent(m_handle);

      //glClearColor(); // TODO vectors
      glClear(getClearMask());
   }

   void Window::draw()
   {
      glfwSwapBuffers(m_handle);
   }

   void Window::show()
   {
      glfwShowWindow(m_handle);
   }

   void Window::hide()
   {
      glfwHideWindow(m_handle);
   }

   void Window::close()
   {
      glfwSetWindowShouldClose(m_handle, GLFW_FALSE);
   }

   void Window::setName(std::string const& name)
   {
      m_name = name;
      glfwSetWindowTitle(m_handle, m_name.c_str());
   }

   void Window::setSize(size_t width, size_t height)
   {
      glfwSetWindowSize(m_handle, static_cast<int>(width), static_cast<int>(height));
   }

   void Window::setPosition(size_t x, size_t y)
   {
      glfwSetWindowPos(m_handle, static_cast<int>(x), static_cast<int>(y));
   }

   void Window::setOpacity(float opacity)
   {
      glfwSetWindowOpacity(m_handle, opacity);
   }

   void Window::setVisible(bool visible)
   {
      visible ? show() : hide();
   }

   void Window::setClearMask(uint32_t mask)
   {
      m_clearMask = mask;
   }

   Window::~Window()
   {
      glfwDestroyWindow(m_handle);
   }
}