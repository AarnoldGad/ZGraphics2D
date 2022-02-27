#ifndef ZGRAPHCIS_HPP
#define ZGRAPHCIS_HPP

#include <zengine/defines.hpp>

// Core
#include <zgraphics2D/Engine/GraphicsEngine.hpp>
#include <zgraphics2D/Engine/GraphicsSettings.hpp>

// Common
#include <zgraphics2D/Common/Colors.hpp>
#include <zgraphics2D/Common/Image.hpp>

// Rendering
#include <zgraphics2D/Window/Window.hpp>
#include <zgraphics2D/Window/ContextSettings.hpp>
#include <zgraphics2D/Window/FrameBufferSettings.hpp>
#include <zgraphics2D/Window/WindowSettings.hpp>

// Renderer
#include <zgraphics2D/Renderer/Shader.hpp>
#include <zgraphics2D/Renderer/Texture.hpp>

#include <zgraphics2D/Renderer/Buffers/VertexArray.hpp>
#include <zgraphics2D/Renderer/Buffers/VertexBuffer.hpp>
#include <zgraphics2D/Renderer/Buffers/IndexBuffer.hpp>

#include <zgraphics2D/Renderer/Renderer.hpp>
#include <zgraphics2D/Renderer/DefaultRenderer.hpp>
#include <zgraphics2D/Renderer/Vertex.hpp>
#include <zgraphics2D/Renderer/Vertex2D.hpp>
#include <zgraphics2D/Renderer/Transform.hpp>

#include <zgraphics2D/Renderer/ViewProjection.hpp>
#include <zgraphics2D/Camera/OrthographicCamera.hpp>
#include <zgraphics2D/Camera/Camera.hpp>
#include <zgraphics2D/Camera/FPSCamera.hpp>

#include <zgraphics2D/Renderable/Renderable.hpp>
#include <zgraphics2D/Renderable/Sprite.hpp>

// Text
#include <zgraphics2D/Text/Font.hpp>
#include <zgraphics2D/Text/BitmapFont.hpp>
#include <zgraphics2D/Text/Glyph.hpp>
#include <zgraphics2D/Text/Encoding.hpp>

// Input
#include <zgraphics2D/Input/Keyboard.hpp>
#include <zgraphics2D/Input/Mouse.hpp>
#include <zgraphics2D/Input/Joystick.hpp>

// Events
#include <zgraphics2D/Input/Event/KeyEvent.hpp>
#include <zgraphics2D/Input/Event/KeyPressedEvent.hpp>
#include <zgraphics2D/Input/Event/KeyReleasedEvent.hpp>
#include <zgraphics2D/Input/Event/KeyRepeatedEvent.hpp>

#include <zgraphics2D/Input/Event/MouseEvent.hpp>
#include <zgraphics2D/Input/Event/MouseMovedEvent.hpp>
#include <zgraphics2D/Input/Event/MouseEnteredEvent.hpp>
#include <zgraphics2D/Input/Event/MouseScrolledEvent.hpp>
#include <zgraphics2D/Input/Event/MouseButtonEvent.hpp>
#include <zgraphics2D/Input/Event/MouseButtonPressedEvent.hpp>
#include <zgraphics2D/Input/Event/MouseButtonReleasedEvent.hpp>
#include <zgraphics2D/Input/Event/MouseDroppedEvent.hpp>

#include <zgraphics2D/Window/Event/WindowEvent.hpp>
#include <zgraphics2D/Window/Event/FrameBufferResisedEvent.hpp>
#include <zgraphics2D/Window/Event/WindowClosedEvent.hpp>
#include <zgraphics2D/Window/Event/WindowFocusedEvent.hpp>
#include <zgraphics2D/Window/Event/WindowIconifiedEvent.hpp>
#include <zgraphics2D/Window/Event/WindowMaximisedEvent.hpp>
#include <zgraphics2D/Window/Event/WindowMovedEvent.hpp>
#include <zgraphics2D/Window/Event/WindowRefreshedEvent.hpp>
#include <zgraphics2D/Window/Event/WindowResisedEvent.hpp>
#include <zgraphics2D/Window/Event/WindowScaledEvent.hpp>

#endif // ZGRAPHCIS_HPP
