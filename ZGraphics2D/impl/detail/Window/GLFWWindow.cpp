#include "zgpch.hpp"

#include "detail/Window/GLFWWindow.hpp"

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

namespace zg { namespace details
{
   void WindowImpl::ConfigureWindow(WindowSettings window, ContextSettings context, FrameBufferSettings framebuffer)
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

      glfwWindowHint(GLFW_CLIENT_API, context.client == ContextSettings::ClientAPI::OpenGLES ? GLFW_OPENGL_ES_API : (
                                      context.client == ContextSettings::ClientAPI::OpenGL ? GLFW_OPENGL_API : GLFW_NO_API));
      glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_NATIVE_CONTEXT_API);
      glfwWindowHint(GLFW_OPENGL_PROFILE, context.openglProfile == ContextSettings::Profile::Core ? GLFW_OPENGL_CORE_PROFILE : (
                                          context.openglProfile == ContextSettings::Profile::Compatibility ? GLFW_OPENGL_COMPAT_PROFILE : GLFW_OPENGL_ANY_PROFILE));
      glfwWindowHint(GLFW_CONTEXT_ROBUSTNESS, GLFW_NO_ROBUSTNESS);
      glfwWindowHint(GLFW_CONTEXT_RELEASE_BEHAVIOR, GLFW_ANY_RELEASE_BEHAVIOR);
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

   WindowImpl::WindowImpl()
      : m_handle(nullptr), m_color(Colors::White),
        m_clearMask(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT) {}
   
   void WindowImpl::open(std::string const& title, glm::ivec2 size, glm::ivec2 pos)
   {
      if (m_handle) return;

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

      glfwSetWindowUserPointer(m_handle, static_cast<void*>(this));

      m_title = title;
      m_size = size;
      m_color = Colors::White;
      m_clearMask = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT;

      setPosition(pos);
   }

   void WindowImpl::clear()
   {
      glfwMakeContextCurrent(m_handle);

      glClearColor(m_color.r, m_color.g, m_color.b, m_color.a);
      glClear(m_clearMask);
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
      if (x == PositionCentered.x || y == PositionCentered.y)
      {
         int monx, mony;
         int monw, monh;
         GLFWmonitor* monitor;
         monitor = glfwGetPrimaryMonitor();
         if (!monitor)
            exit(-1); // TODO Error handling

         glfwGetMonitorWorkarea(monitor, &monx, &mony, &monw, &monh);
         setPosition(x == PositionCentered.x ? monx + (monw - m_size.x) / 2 : x,
                     y == PositionCentered.y ? mony + (monh - m_size.y) / 2 : y);
      }
      else if (glm::ivec2(x, y) != PositionUndefined)
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

   void WindowImpl::setColor(float r, float g, float b, float a) noexcept
   {
      setColor({ r, g, b, a });
   }

   void WindowImpl::setColor(glm::vec4 color) noexcept
   {
      m_color = color;
   }

   void WindowImpl::setClearMask(uint32_t mask) noexcept
   {
      m_clearMask = mask;
   }

   void WindowImpl::Moved(GLFWwindow* window, int x, int y)
   {
      WindowImpl* windowPtr = reinterpret_cast<WindowImpl*>(glfwGetWindowUserPointer(window));
      ::ze::Core::UseEventBus().pushEvent<WindowMovedEvent>(static_cast<Window*>(windowPtr), glm::ivec2(x, y), windowPtr->m_pos);
      windowPtr->m_pos = { x, y };
   }

   void WindowImpl::Resised(GLFWwindow* window, int width, int height)
   {
      WindowImpl* windowPtr = reinterpret_cast<WindowImpl*>(glfwGetWindowUserPointer(window));
      ::ze::Core::UseEventBus().pushEvent<WindowResisedEvent>(static_cast<Window*>(windowPtr), glm::ivec2(width, height), windowPtr->m_size);
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

   WindowImpl::~WindowImpl()
   {
      glfwDestroyWindow(m_handle);
   }
}}

