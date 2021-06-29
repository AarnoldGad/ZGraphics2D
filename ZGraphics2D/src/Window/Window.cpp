#include "zgraphics2D/Window/Window.hpp"

#include "zgraphics2D/Window/WindowClosedEvent.hpp"

#include <zengine/Memory/New.hpp>

namespace zg
{
   Window::Window()
      : m_clearMask(GL_COLOR_BUFFER_BIT), m_clearColor(0.8f, 0.5f, 0.1f, 1.f), m_handle(nullptr) {}

   Window::Window(std::string const& title, int width, int height, WindowSettings settings)
      : m_handle(nullptr), m_title(title), m_clearMask(settings.clearMask), m_clearColor(settings.clearColor)
   {
      create(title, width, height, settings);
   }

   void Window::create(std::string const& title, int width, int height, WindowSettings settings)
   {
      if (m_handle) return;

      m_title = title;
      m_clearMask = settings.clearMask;
      m_clearColor = settings.clearColor;

      configureWindow(settings);
      makeWindow(title, width, height);
      installWindow();

      glfwSetWindowUserPointer(m_handle, static_cast<void*>(this));
   }

   void Window::clear()
   {
      if (glfwGetCurrentContext() != getHandle())
         glfwMakeContextCurrent(m_handle);

      glClearColor(m_clearColor.r, m_clearColor.g, m_clearColor.b, m_clearColor.a);
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

   void Window::setClearColor(glm::vec4 color)
   {
      m_clearColor = color;
   }

   void Window::setClearMask(uint32_t mask)
   {
      m_clearMask = mask;
   }

   void Window::configureWindow(WindowSettings settings)
   {
      glfwWindowHint(GLFW_RESIZABLE, settings.resisable ? GLFW_TRUE : GLFW_FALSE);
      glfwWindowHint(GLFW_VISIBLE, settings.visible ? GLFW_TRUE : GLFW_FALSE);
      glfwWindowHint(GLFW_DECORATED, settings.decorated ? GLFW_TRUE : GLFW_FALSE);
      glfwWindowHint(GLFW_FOCUSED, settings.focused ? GLFW_TRUE : GLFW_FALSE);
      glfwWindowHint(GLFW_AUTO_ICONIFY, settings.autoIconify ? GLFW_TRUE : GLFW_FALSE);
      glfwWindowHint(GLFW_FLOATING, settings.floating ? GLFW_TRUE : GLFW_FALSE);
      glfwWindowHint(GLFW_MAXIMIZED, settings.maximised ? GLFW_TRUE : GLFW_FALSE);
      glfwWindowHint(GLFW_CENTER_CURSOR, settings.centerCursor ? GLFW_TRUE : GLFW_FALSE);
      glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, settings.transparent ? GLFW_TRUE : GLFW_FALSE);
      glfwWindowHint(GLFW_FOCUS_ON_SHOW, settings.focusOnShow ? GLFW_TRUE : GLFW_FALSE);
      glfwWindowHint(GLFW_SCALE_TO_MONITOR, settings.scaleToMonitor ? GLFW_TRUE : GLFW_FALSE);
      glfwWindowHint(GLFW_SRGB_CAPABLE, settings.srgbCapable ? GLFW_TRUE : GLFW_FALSE);
      glfwWindowHint(GLFW_SRGB_CAPABLE, settings.srgbCapable ? GLFW_TRUE : GLFW_FALSE);
      glfwWindowHint(GLFW_STEREO, settings.stereo ? GLFW_TRUE : GLFW_FALSE);
      glfwWindowHint(GLFW_DOUBLEBUFFER, settings.doubleBuffering ? GLFW_TRUE : GLFW_FALSE);
      glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, settings.forwardCompatibility ? GLFW_TRUE : GLFW_FALSE);
      glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, settings.debugContext ? GLFW_TRUE : GLFW_FALSE);
      //glfwWindowHint(GLFW_CONTEXT_NO_ERROR,        settings.noError ? GLFW_TRUE : GLFW_FALSE);

      glfwWindowHint(GLFW_RED_BITS, settings.redBits >= 0 ? settings.redBits : GLFW_DONT_CARE);
      glfwWindowHint(GLFW_GREEN_BITS, settings.greenBits >= 0 ? settings.greenBits : GLFW_DONT_CARE);
      glfwWindowHint(GLFW_BLUE_BITS, settings.blueBits >= 0 ? settings.blueBits : GLFW_DONT_CARE);
      glfwWindowHint(GLFW_ALPHA_BITS, settings.alphaBits >= 0 ? settings.alphaBits : GLFW_DONT_CARE);
      glfwWindowHint(GLFW_DEPTH_BITS, settings.depthBits >= 0 ? settings.depthBits : GLFW_DONT_CARE);
      glfwWindowHint(GLFW_STENCIL_BITS, settings.stencilBits >= 0 ? settings.stencilBits : GLFW_DONT_CARE);
      glfwWindowHint(GLFW_ACCUM_RED_BITS, settings.accumRedBits >= 0 ? settings.accumRedBits : GLFW_DONT_CARE);
      glfwWindowHint(GLFW_ACCUM_GREEN_BITS, settings.accumGreenBits >= 0 ? settings.accumGreenBits : GLFW_DONT_CARE);
      glfwWindowHint(GLFW_ACCUM_BLUE_BITS, settings.accumBlueBits >= 0 ? settings.accumBlueBits : GLFW_DONT_CARE);
      glfwWindowHint(GLFW_ACCUM_ALPHA_BITS, settings.accumAlphaBits >= 0 ? settings.accumAlphaBits : GLFW_DONT_CARE);
      //glfwWindowHint(GLFW_AUX_BUFFERS, 0);
      glfwWindowHint(GLFW_SAMPLES, settings.samples >= 0 ? settings.samples : GLFW_DONT_CARE);
      glfwWindowHint(GLFW_REFRESH_RATE, settings.refreshRate >= 0 ? settings.refreshRate : GLFW_DONT_CARE);

      glfwWindowHint(GLFW_CLIENT_API, static_cast<int>(settings.api));
      glfwWindowHint(GLFW_CONTEXT_CREATION_API, static_cast<int>(settings.context));
      glfwWindowHint(GLFW_OPENGL_PROFILE, static_cast<int>(settings.openglProfile));
      glfwWindowHint(GLFW_CONTEXT_ROBUSTNESS, static_cast<int>(settings.robustness));
      glfwWindowHint(GLFW_CONTEXT_RELEASE_BEHAVIOR, static_cast<int>(settings.releaseBehavior));

      glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, settings.versionMajor);
      glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, settings.versionMinor);

      //glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, settings.cocoa_retinaFrameBuffer ? GLFW_TRUE : GLFW_FALSE);
      //glfwWindowHint(GLFW_COCOA_GRAPHICS_SWITCHING, settings.cocoa_graphicsSwitching ? GLFW_TRUE : GLFW_FALSE);
      //glfwWindowHintString(GLFW_COCOA_FRAME_NAME,   settings.cocoa_frameName.c_str());

      //glfwWindowHintString(GLFW_X11_CLASS_NAME,    settings.x11_className.c_str());
      //glfwWindowHintString(GLFW_X11_INSTANCE_NAME, settings.x11_instanceName.c_str());
   }

   void Window::makeWindow(std::string const& title, int width, int height)
   {
      // TODO Monitor and position
      m_handle = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
      if (!m_handle)
         exit(-1); // TODO Error handling

      glfwMakeContextCurrent(m_handle);
   }

   void Window::installWindow()
   {
      glfwSetWindowPosCallback(m_handle, &Window::Moved);
      glfwSetWindowSizeCallback(m_handle, &Window::Resised);
      glfwSetWindowCloseCallback(m_handle, &Window::Closed);
      glfwSetWindowRefreshCallback(m_handle, &Window::Refreshed);
      glfwSetWindowFocusCallback(m_handle, &Window::Focused);
      glfwSetWindowIconifyCallback(m_handle, &Window::Iconified);
      glfwSetWindowMaximizeCallback(m_handle, &Window::Maximised);
      glfwSetFramebufferSizeCallback(m_handle, &Window::FramebufferResised);
      glfwSetWindowContentScaleCallback(m_handle, &Window::Scaled);

      //glfwSetCursorPosCallback(m_handle, &Window::CursorPositionInput);
      //glfwSetCursorEnterCallback(m_handle, &Window::CursorEnterInput);

      //glfwSetMouseButtonCallback(m_handle, &Window::MouseButtonInput);
      //glfwSetScrollCallback(m_handle, &Window::MouseWheelInput);

      //glfwSetDropCallback(m_handle, &Window::DropInput);
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

   /*void Window::CursorPositionInput(GLFWwindow* window, double x, double y) noexcept
   {

   }

   void Window::CursorEnterInput(GLFWwindow* window, int entered) noexcept
   {

   }

   void Window::MouseButtonInput(GLFWwindow* window, int button, int type, int mods) noexcept
   {

   }

   void Window::MouseWheelInput(GLFWwindow* window, double dx, double dy) noexcept
   {

   }

   void Window::DropInput(GLFWwindow* window, int count, char const* paths[]) noexcept
   {

   }*/

   Window::~Window()
   {
      glfwDestroyWindow(m_handle);
   }
}
