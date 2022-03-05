#include "zgpch.hpp"

#include "detail/Window/WindowImpl.hpp"
#include "detail/Input/KeyboardImpl.hpp"
#include "detail/Input/MouseImpl.hpp"

#include "zgraphics2D/Engine/GraphicsEngine.hpp"
#include "zgraphics2D/Common/Image.hpp"
#include "zgraphics2D/Window/Event/WindowMovedEvent.hpp"
#include "zgraphics2D/Window/Event/WindowClosedEvent.hpp"
#include "zgraphics2D/Window/Event/WindowResisedEvent.hpp"
#include "zgraphics2D/Window/Event/WindowRefreshedEvent.hpp"
#include "zgraphics2D/Window/Event/WindowFocusedEvent.hpp"
#include "zgraphics2D/Window/Event/WindowIconifiedEvent.hpp"
#include "zgraphics2D/Window/Event/WindowMaximisedEvent.hpp"
#include "zgraphics2D/Window/Event/FrameBufferResisedEvent.hpp"
#include "zgraphics2D/Window/Event/WindowScaledEvent.hpp"

#include "zgraphics2D/Input/Event/KeyPressedEvent.hpp"
#include "zgraphics2D/Input/Event/KeyReleasedEvent.hpp"
#include "zgraphics2D/Input/Event/KeyRepeatedEvent.hpp"

#include "zgraphics2D/Input/Event/MouseButtonPressedEvent.hpp"
#include "zgraphics2D/Input/Event/MouseButtonReleasedEvent.hpp"
#include "zgraphics2D/Input/Event/MouseMovedEvent.hpp"
#include "zgraphics2D/Input/Event/MouseScrolledEvent.hpp"
#include "zgraphics2D/Input/Event/MouseEnteredEvent.hpp"
#include "zgraphics2D/Input/Event/MouseDroppedEvent.hpp"

namespace zg { namespace details
{
   WindowImpl::WindowImpl(Window* root)
      : m_root(root), m_handle(nullptr), m_color(Colors::White) {}

   WindowImpl::WindowImpl(Window* root, std::string const& title, glm::ivec2 size, glm::ivec2 pos)
      : m_root(root), m_handle(nullptr), m_color(Colors::White)
   {
      open(title, size, pos);
   }

   
   void WindowImpl::open(std::string const& title, glm::ivec2 size, glm::ivec2 pos)
   {
      if (m_handle)
      {
         glfwDestroyWindow(m_handle);
         m_handle = nullptr;
      }

      // TODO Monitor/error handling
      m_handle = glfwCreateWindow(size.x, size.y, title.c_str(), nullptr, nullptr);
      if (!m_handle)
      {
         GFX_LOG_CRITICAL("Fail to create window !");
         ze::RaiseCritical(-1, "Fail to create window !");
      }

      glfwMakeContextCurrent(m_handle);

      glfwSetWindowPosCallback(m_handle, &WindowImpl::Moved);
      glfwSetWindowSizeCallback(m_handle, &WindowImpl::Resised);
      glfwSetWindowCloseCallback(m_handle, &WindowImpl::Closed);
      glfwSetWindowRefreshCallback(m_handle, &WindowImpl::Refreshed);
      glfwSetWindowFocusCallback(m_handle, &WindowImpl::Focused);
      glfwSetWindowIconifyCallback(m_handle, &WindowImpl::Iconified);
      glfwSetWindowMaximizeCallback(m_handle, &WindowImpl::Maximised);
      glfwSetFramebufferSizeCallback(m_handle, &WindowImpl::FramebufferResised);
      glfwSetWindowContentScaleCallback(m_handle, &WindowImpl::Scaled);

      glfwSetKeyCallback(m_handle, &WindowImpl::KeyInput);
      glfwSetCharCallback(m_handle, &WindowImpl::TextInput);

      glfwSetCursorPosCallback(m_handle, &WindowImpl::CursorPositionInput);
      glfwSetCursorEnterCallback(m_handle, &WindowImpl::CursorEnterInput);
      glfwSetMouseButtonCallback(m_handle, &WindowImpl::MouseButtonInput);
      glfwSetScrollCallback(m_handle, &WindowImpl::MouseWheelInput);
      glfwSetDropCallback(m_handle, &WindowImpl::DropInput);

      glfwSetWindowUserPointer(m_handle, static_cast<void*>(this));

      m_title = title;
      m_size = size;
      m_color = Colors::White;

      setPosition(pos);
   }

   void WindowImpl::clear()
   {
      glfwMakeContextCurrent(m_handle);

      glClearColor(m_color.r, m_color.g, m_color.b, m_color.a);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
   }

   void WindowImpl::draw()
   {
      glfwSwapBuffers(m_handle);
   }

   void WindowImpl::show()
   {
      glfwShowWindow(m_handle);
   }

   void WindowImpl::hide()
   {
      glfwHideWindow(m_handle);
   }

   void WindowImpl::close()
   {
      glfwSetWindowShouldClose(m_handle, GLFW_FALSE);
   }

   void WindowImpl::setTitle(std::string const& title)
   {
      m_title = title;
      glfwSetWindowTitle(m_handle, m_title.c_str());
   }

   void WindowImpl::setSize(int width, int height)
   {
      m_size = { width, height };
      glfwSetWindowSize(m_handle, width, height);
   }

   void WindowImpl::setSize(glm::ivec2 size)
   {
      setSize(size.x, size.y);
   }

   void WindowImpl::setIcon(Image const& icon)
   {
      if (icon.getFormat() == Image::Format::RGBA && icon)
      {
         // TODO Remove const cast
         GLFWimage const img{ static_cast<int>(icon.getSize().x), static_cast<int>(icon.getSize().y), const_cast<unsigned char*>(icon.getData()) };
         glfwSetWindowIcon(m_handle, 1, &img);
      }
   }

   void WindowImpl::setPosition(int x, int y)
   {
      if (x == Window::PositionCentered.x || y == Window::PositionCentered.y)
      {
         int monx, mony;
         int monw, monh;
         GLFWmonitor* monitor;
         monitor = glfwGetPrimaryMonitor();
         if (!monitor)
            exit(-1); // TODO Error handling

         glfwGetMonitorWorkarea(monitor, &monx, &mony, &monw, &monh);
         setPosition(x == Window::PositionCentered.x ? monx + (monw - m_size.x) / 2 : x,
                     y == Window::PositionCentered.y ? mony + (monh - m_size.y) / 2 : y);
      }
      else if (glm::ivec2(x, y) != Window::PositionUndefined)
         glfwSetWindowPos(m_handle, x, y);

      m_pos = { x, y };
   }

   void WindowImpl::setPosition(glm::ivec2 pos)
   {
      setPosition(pos.x, pos.y);
   }

   void WindowImpl::setOpacity(float opacity)
   {
      glfwSetWindowOpacity(m_handle, opacity);
   }

   void WindowImpl::setVisible(bool visible)
   {
      visible ? show() : hide();
   }

   void WindowImpl::setColor(float r, float g, float b, float a)
   {
      setColor({ r, g, b, a });
   }

   void WindowImpl::setColor(glm::vec4 color)
   {
      m_color = color;
   }

   void WindowImpl::Moved(GLFWwindow* window, int x, int y)
   {
      WindowImpl* windowPtr = reinterpret_cast<WindowImpl*>(glfwGetWindowUserPointer(window));
      ::ze::Core::UseEventBus().pushEvent<WindowMovedEvent>(windowPtr->m_root, glm::ivec2(x, y), windowPtr->m_pos);
      windowPtr->m_pos = { x, y };
   }

   void WindowImpl::Resised(GLFWwindow* window, int width, int height)
   {
      WindowImpl* windowPtr = reinterpret_cast<WindowImpl*>(glfwGetWindowUserPointer(window));
      ::ze::Core::UseEventBus().pushEvent<WindowResisedEvent>(windowPtr->m_root, glm::ivec2(width, height), windowPtr->m_size);
      windowPtr->m_size = { width, height };
   }

   void WindowImpl::Closed(GLFWwindow* window)
   {
      PushWindowEvent<WindowClosedEvent>(window);
   }

   void WindowImpl::Refreshed(GLFWwindow* window)
   {
      PushWindowEvent<WindowRefreshedEvent>(window);
   }

   void WindowImpl::Focused(GLFWwindow* window, int focused)
   {
      if (focused)
      {
         WindowImpl* windowPtr = reinterpret_cast<WindowImpl*>(glfwGetWindowUserPointer(window));
         KeyboardImpl::SetFocusedWindow(windowPtr->m_root);
         MouseImpl::SetFocusedWindow(windowPtr->m_root);
      }

      PushWindowEvent<WindowFocusedEvent>(window, static_cast<bool>(focused));
   }

   void WindowImpl::Iconified(GLFWwindow* window, int iconified)
   {
      PushWindowEvent<WindowIconifiedEvent>(window, iconified);
   }

   void WindowImpl::Maximised(GLFWwindow* window, int maximised)
   {
      PushWindowEvent<WindowMaximisedEvent>(window, maximised);
   }

   void WindowImpl::FramebufferResised(GLFWwindow* window, int width, int height)
   {
      PushWindowEvent<FrameBufferResisedEvent>(window, width, height);
   }

   void WindowImpl::Scaled(GLFWwindow* window, float xscale, float yscale)
   {
      PushWindowEvent<WindowScaledEvent>(window, xscale, yscale);
   }

   void WindowImpl::KeyInput(GLFWwindow* window, int key, int scancode, int type, int modifiers)
   {
      switch (type)
      {
         case GLFW_RELEASE:
            PushKeyEvent<KeyReleasedEvent>(window, key, scancode, modifiers);
            break;
         case GLFW_PRESS:
            PushKeyEvent<KeyPressedEvent>(window, key, scancode, modifiers);
            break;
         case GLFW_REPEAT:
            PushKeyEvent<KeyRepeatedEvent>(window, key, scancode, modifiers);
            break;
         default:
            break;
      }
   }

   void WindowImpl::TextInput(GLFWwindow* window, uint32_t codepoint)
   {
      // TODO
   }

   void WindowImpl::CursorPositionInput(GLFWwindow* window, double x, double y)
   {
      WindowImpl* windowPtr = reinterpret_cast<WindowImpl*>(glfwGetWindowUserPointer(window));
      ze::Core::UseEventBus().pushEvent<MouseMovedEvent>(windowPtr->m_root, glm::ivec2(glm::floor(x), glm::floor(y)));
   }

   void WindowImpl::CursorEnterInput(GLFWwindow* window, int entered)
   {
      PushMouseEvent<MouseEnteredEvent>(window, static_cast<bool>(entered));
   }

   void WindowImpl::MouseButtonInput(GLFWwindow* window, int button, int type, int mods)
   {
      switch (type)
      {
         case GLFW_RELEASE:
            PushMouseEvent<MouseButtonReleasedEvent>(window, static_cast<Mouse::Button>(button),
                                                     static_cast<uint32_t>(mods));
            break;
         case GLFW_PRESS:
            PushMouseEvent<MouseButtonPressedEvent>(window, static_cast<Mouse::Button>(button),
                                                    static_cast<uint32_t>(mods));
            break;
         default:
            break;
      }
   }

   void WindowImpl::MouseWheelInput(GLFWwindow* window, double dx, double dy)
   {
      PushMouseEvent<MouseScrolledEvent>(window, dx, dy);
   }

   void WindowImpl::DropInput(GLFWwindow* window, int count, char const* paths[])
   {
      PushMouseEvent<MouseDroppedEvent>(window, count, paths);
   }

   WindowImpl::~WindowImpl()
   {
      glfwDestroyWindow(m_handle);
   }
}}

