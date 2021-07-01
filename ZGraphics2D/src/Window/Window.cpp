#include "zgraphics2D/Window/Window.hpp"

#include "zgraphics2D/Engine/GraphicsEngine.hpp"
#include "zgraphics2D/Window/Event/WindowClosedEvent.hpp"

#include <zengine/Memory/New.hpp>

namespace zg
{
   Window::Window()
      : m_handle(nullptr) {}

   Window::Window(std::string const& title, glm::ivec2 size, glm::ivec2 pos, glm::vec4 color, uint32_t clearMask,
                  WindowSettings window, ContextSettings context, FrameBufferSettings framebuffer)
      : m_handle(nullptr), m_title(title), m_size(size), m_color(color), m_clearMask(clearMask)
   {
      configure(window, context, framebuffer);
      make(title, size, pos, color, clearMask);
   }

   void Window::configure(WindowSettings window, ContextSettings context, FrameBufferSettings framebuffer)
   {
      glfwWindowHint(GLFW_RESIZABLE, window.resisable ? GLFW_TRUE : GLFW_FALSE);
      glfwWindowHint(GLFW_VISIBLE, window.visible ? GLFW_TRUE : GLFW_FALSE);
      glfwWindowHint(GLFW_DECORATED, window.decorated ? GLFW_TRUE : GLFW_FALSE);
      glfwWindowHint(GLFW_FOCUSED, window.focused ? GLFW_TRUE : GLFW_FALSE);
      glfwWindowHint(GLFW_AUTO_ICONIFY, window.autoIconify ? GLFW_TRUE : GLFW_FALSE);
      glfwWindowHint(GLFW_FLOATING, window.floating ? GLFW_TRUE : GLFW_FALSE);
      glfwWindowHint(GLFW_MAXIMIZED, window.maximised ? GLFW_TRUE : GLFW_FALSE);
      glfwWindowHint(GLFW_CENTER_CURSOR, window.centerCursor ? GLFW_TRUE : GLFW_FALSE);
      glfwWindowHint(GLFW_FOCUS_ON_SHOW, window.focusOnShow ? GLFW_TRUE : GLFW_FALSE);
      glfwWindowHint(GLFW_SCALE_TO_MONITOR, window.scaleToMonitor ? GLFW_TRUE : GLFW_FALSE);
      glfwWindowHint(GLFW_DOUBLEBUFFER, window.doubleBuffering ? GLFW_TRUE : GLFW_FALSE);
      glfwWindowHint(GLFW_REFRESH_RATE, window.refreshRate >= 0 ? window.refreshRate : GLFW_DONT_CARE);
      //glfwWindowHint(GLFW_CONTEXT_NO_ERROR,        settings.noError ? GLFW_TRUE : GLFW_FALSE);

      glfwWindowHint(GLFW_RED_BITS, framebuffer.redBits >= 0 ? framebuffer.redBits : GLFW_DONT_CARE);
      glfwWindowHint(GLFW_GREEN_BITS, framebuffer.greenBits >= 0 ? framebuffer.greenBits : GLFW_DONT_CARE);
      glfwWindowHint(GLFW_BLUE_BITS, framebuffer.blueBits >= 0 ? framebuffer.blueBits : GLFW_DONT_CARE);
      glfwWindowHint(GLFW_ALPHA_BITS, framebuffer.alphaBits >= 0 ? framebuffer.alphaBits : GLFW_DONT_CARE);
      glfwWindowHint(GLFW_DEPTH_BITS, framebuffer.depthBits >= 0 ? framebuffer.depthBits : GLFW_DONT_CARE);
      glfwWindowHint(GLFW_STENCIL_BITS, framebuffer.stencilBits >= 0 ? framebuffer.stencilBits : GLFW_DONT_CARE);
      glfwWindowHint(GLFW_ACCUM_RED_BITS, framebuffer.accumRedBits >= 0 ? framebuffer.accumRedBits : GLFW_DONT_CARE);
      glfwWindowHint(GLFW_ACCUM_GREEN_BITS, framebuffer.accumGreenBits >= 0 ? framebuffer.accumGreenBits : GLFW_DONT_CARE);
      glfwWindowHint(GLFW_ACCUM_BLUE_BITS, framebuffer.accumBlueBits >= 0 ? framebuffer.accumBlueBits : GLFW_DONT_CARE);
      glfwWindowHint(GLFW_ACCUM_ALPHA_BITS, framebuffer.accumAlphaBits >= 0 ? framebuffer.accumAlphaBits : GLFW_DONT_CARE);
      glfwWindowHint(GLFW_SRGB_CAPABLE, framebuffer.srgbCapable ? GLFW_TRUE : GLFW_FALSE);
      glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, framebuffer.transparent ? GLFW_TRUE : GLFW_FALSE);

      //glfwWindowHint(GLFW_AUX_BUFFERS, 0);

      glfwWindowHint(GLFW_CLIENT_API, static_cast<int>(context.client));
      glfwWindowHint(GLFW_CONTEXT_CREATION_API, static_cast<int>(context.api));
      glfwWindowHint(GLFW_OPENGL_PROFILE, static_cast<int>(context.openglProfile));
      glfwWindowHint(GLFW_CONTEXT_ROBUSTNESS, static_cast<int>(context.robustness));
      glfwWindowHint(GLFW_CONTEXT_RELEASE_BEHAVIOR, static_cast<int>(context.releaseBehavior));
      glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, context.versionMajor);
      glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, context.versionMinor);
      glfwWindowHint(GLFW_SAMPLES, context.samples >= 0 ? context.samples : GLFW_DONT_CARE);
      glfwWindowHint(GLFW_STEREO, context.stereo ? GLFW_TRUE : GLFW_FALSE);
      glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, context.forwardCompatibility ? GLFW_TRUE : GLFW_FALSE);
      glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, context.debugContext ? GLFW_TRUE : GLFW_FALSE);

      //glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, settings.cocoa.retinaFrameBuffer ? GLFW_TRUE : GLFW_FALSE);
      //glfwWindowHint(GLFW_COCOA_GRAPHICS_SWITCHING, settings.cocoa.graphicsSwitching ? GLFW_TRUE : GLFW_FALSE);
      //glfwWindowHintString(GLFW_COCOA_FRAME_NAME,   settings.cocoa.frameName.c_str());

      //glfwWindowHintString(GLFW_X11_CLASS_NAME,    settings.x11.className.c_str());
      //glfwWindowHintString(GLFW_X11_INSTANCE_NAME, settings.x11.instanceName.c_str());
   }

   void Window::make(std::string const& title, glm::ivec2 size, glm::ivec2 pos, glm::vec4 color, uint32_t clearMask)
   {
      if (m_handle) return;

      m_title = title;
      m_size = size;
      m_color = color;
      m_clearMask = clearMask;

      // TODO Monitor
      m_handle = glfwCreateWindow(m_size.x, m_size.y, m_title.c_str(), nullptr, nullptr);
      if (!m_handle)
      {
         GFX_LOG_CRITICAL("Fail to create window !");
         exit(-1); // TODO Error handling
      }

      glfwMakeContextCurrent(m_handle);

      if (pos == PositionCentered)
      {
         int x, y;
         int w, h;
         GLFWmonitor* monitor;
         monitor = glfwGetPrimaryMonitor();
         if (!monitor)
            exit(-1); // TODO Error handling

         glfwGetMonitorWorkarea(monitor, &x, &y, &w, &h);
         setPosition(x + (w - m_size.x) / 2, y + (h - m_size.y) / 2);
      }
      else if (pos != PositionUndefined)
         setPosition(pos);

      glfwSetWindowPosCallback(m_handle, &Window::Moved);
      glfwSetWindowSizeCallback(m_handle, &Window::Resised);
      glfwSetWindowCloseCallback(m_handle, &Window::Closed);
      glfwSetWindowRefreshCallback(m_handle, &Window::Refreshed);
      glfwSetWindowFocusCallback(m_handle, &Window::Focused);
      glfwSetWindowIconifyCallback(m_handle, &Window::Iconified);
      glfwSetWindowMaximizeCallback(m_handle, &Window::Maximised);
      glfwSetFramebufferSizeCallback(m_handle, &Window::FramebufferResised);
      glfwSetWindowContentScaleCallback(m_handle, &Window::Scaled);

      glfwSetWindowUserPointer(m_handle, static_cast<void*>(this));
   }

   void Window::clear()
   {
      if (glfwGetCurrentContext() != getHandle())
         glfwMakeContextCurrent(m_handle);

      glClearColor(m_color.r, m_color.g, m_color.b, m_color.a);
      glClear(m_clearMask);
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

   void Window::setTitle(std::string const& title)
   {
      m_title = title;
      glfwSetWindowTitle(m_handle, m_title.c_str());
   }

   void Window::setSize(int width, int height)
   {
      m_size.x = width;
      m_size.y = height;
      glfwSetWindowSize(m_handle, width, height);
   }

   void Window::setSize(glm::ivec2 size)
   {
      setSize(size.x, size.y);
   }

   void Window::setPosition(int x, int y)
   {
      glfwSetWindowPos(m_handle, x, y);
   }

   void Window::setPosition(glm::ivec2 pos)
   {
      setPosition(pos.x, pos.y);
   }

   void Window::setOpacity(float opacity)
   {
      glfwSetWindowOpacity(m_handle, opacity);
   }

   void Window::setVisible(bool visible)
   {
      visible ? show() : hide();
   }

   void Window::setColor(glm::vec4 color) noexcept
   {
      m_color = color;
   }

   void Window::setClearMask(uint32_t mask) noexcept
   {
      m_clearMask = mask;
   }

   void Window::Moved(GLFWwindow* window, int x, int y)
   {
      // TODO
   }

   void Window::Resised(GLFWwindow* window, int width, int height)
   {
      // TODO
   }

   void Window::Closed(GLFWwindow* window)
   {
      PushWindowEvent<WindowClosedEvent>(window);
   }

   void Window::Refreshed(GLFWwindow* window)
   {
      // TODO
   }

   void Window::Focused(GLFWwindow* window, int focused)
   {
      // TODO
   }

   void Window::Iconified(GLFWwindow* window, int iconified)
   {
      // TODO
   }

   void Window::Maximised(GLFWwindow* window, int maximised)
   {
      // TODO
   }

   void Window::FramebufferResised(GLFWwindow* window, int width, int height)
   {
      // TODO
   }

   void Window::Scaled(GLFWwindow* window, float xscale, float yscale)
   {
      // TODO
   }

   Window::~Window()
   {
      glfwDestroyWindow(m_handle);
   }
}
