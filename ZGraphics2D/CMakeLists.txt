ADD_LIBRARY(zgraphics)

IF(WIN32)
	SET(BUILD_SHARED_LIBS OFF)
ELSE()
	SET(BUILD_SHARED_LIBS ON)
ENDIF()

# Properties
SET_TARGET_PROPERTIES(zgraphics PROPERTIES
                      OUTPUT_NAME zgraphics2D
                      VERSION ${ZGraphics2D_VERSION_MAJOR}.${ZGraphics2D_VERSION_MINOR}.${ZGraphics2D_VERSION_PATCH}
                      SOVERSION ${ZGraphics2D_VERSION_MAJOR}
                      POSITION_INDEPENDENT_CODE ON
                      CXX_STANDARD 20
                      CXX_STANDARD_REQUIRED ON
                      CXX_EXTENSIONS OFF
                      FOLDER "ZGraphics2D"
                      )

# Precompiled Header
TARGET_PRECOMPILE_HEADERS(zgraphics PRIVATE
                          "$<$<COMPILE_LANGUAGE:CXX>:zgpch.hpp>"
                          )

# include
TARGET_SOURCES(zgraphics PRIVATE
               include/zgpch.hpp
               include/zgraphics2D/defines.hpp
               include/zgraphics2D/platform.hpp
               include/zgraphics2D/zgraphics2D.hpp
               )

# src/Camera
TARGET_SOURCES(zgraphics PRIVATE
               include/zgraphics2D/Camera/Camera.hpp
               include/zgraphics2D/Camera/Camera.inl
               include/zgraphics2D/Camera/FPSCamera.hpp
               include/zgraphics2D/Camera/FPSCamera.inl
               include/zgraphics2D/Camera/OrthographicCamera.hpp
               include/zgraphics2D/Camera/OrthographicCamera.inl
               src/Camera/Camera.cpp
               src/Camera/FPSCamera.cpp
               src/Camera/OrthographicCamera.cpp
               )

# src/Common
TARGET_SOURCES(zgraphics PRIVATE
               include/zgraphics2D/Common/Colors.hpp
               include/zgraphics2D/Common/Image.hpp
               include/zgraphics2D/Common/Image.inl
               src/Common/Image.cpp
               )

# src/Engine
TARGET_SOURCES(zgraphics PRIVATE
               include/zgraphics2D/Engine/GraphicsEngine.hpp
               include/zgraphics2D/Engine/GraphicsEngine.inl
               include/zgraphics2D/Engine/GraphicsSettings.hpp
               src/Engine/GraphicsEngine.cpp
               )

# src/Input
TARGET_SOURCES(zgraphics PRIVATE
               include/zgraphics2D/Input/Joystick.hpp
               include/zgraphics2D/Input/Keyboard.hpp
               include/zgraphics2D/Input/Keyboard.inl
               include/zgraphics2D/Input/Mouse.hpp
               include/zgraphics2D/Input/Mouse.inl
               src/Input/Joystick.cpp
               src/Input/Keyboard.cpp
               src/Input/Mouse.cpp

               include/zgraphics2D/Input/Event/KeyEvent.hpp
               include/zgraphics2D/Input/Event/KeyEvent.inl
               include/zgraphics2D/Input/Event/KeyPressedEvent.hpp
               include/zgraphics2D/Input/Event/KeyReleasedEvent.hpp
               include/zgraphics2D/Input/Event/KeyRepeatedEvent.hpp
               src/Input/Event/KeyEvent.cpp
               src/Input/Event/KeyPressedEvent.cpp
               src/Input/Event/KeyReleasedEvent.cpp
               src/Input/Event/KeyRepeatedEvent.cpp

               include/zgraphics2D/Input/Event/MouseEvent.hpp
               include/zgraphics2D/Input/Event/MouseEvent.inl
               include/zgraphics2D/Input/Event/MouseScrolledEvent.hpp
               include/zgraphics2D/Input/Event/MouseScrolledEvent.inl
               include/zgraphics2D/Input/Event/MouseMovedEvent.hpp
               include/zgraphics2D/Input/Event/MouseButtonEvent.hpp
               include/zgraphics2D/Input/Event/MouseButtonEvent.inl
               include/zgraphics2D/Input/Event/MouseButtonPressedEvent.hpp
               include/zgraphics2D/Input/Event/MouseButtonReleasedEvent.hpp
               include/zgraphics2D/Input/Event/MouseDroppedEvent.hpp
               include/zgraphics2D/Input/Event/MouseDroppedEvent.inl
               include/zgraphics2D/Input/Event/MouseEnteredEvent.hpp
               include/zgraphics2D/Input/Event/MouseEnteredEvent.inl
               src/Input/Event/MouseEvent.cpp
               src/Input/Event/MouseScrolledEvent.cpp
               src/Input/Event/MouseMovedEvent.cpp
               src/Input/Event/MouseButtonEvent.cpp
               src/Input/Event/MouseButtonPressedEvent.cpp
               src/Input/Event/MouseButtonReleaseEvent.cpp
               src/Input/Event/MouseDroppedEvent.cpp
               src/Input/Event/MouseEnteredEvent.cpp
               )

# src/Renderable
TARGET_SOURCES(zgraphics PRIVATE
               include/zgraphics2D/Renderable/Cube.hpp
               include/zgraphics2D/Renderable/Cube.inl
               include/zgraphics2D/Renderable/Renderable.hpp
               include/zgraphics2D/Renderable/Sprite.hpp
               include/zgraphics2D/Renderable/Sprite.inl
               src/Renderable/Sprite.cpp
               src/Renderable/Cube.cpp
               )

# src/Renderer
TARGET_SOURCES(zgraphics PRIVATE
               include/zgraphics2D/Renderer/Renderer.hpp
               include/zgraphics2D/Renderer/DefaultRenderer.hpp
               include/zgraphics2D/Renderer/Transform.hpp
               include/zgraphics2D/Renderer/Transform.inl
               include/zgraphics2D/Renderer/Vertex.hpp
               include/zgraphics2D/Renderer/Vertex2D.hpp
               include/zgraphics2D/Renderer/Vertex2D.inl
               include/zgraphics2D/Renderer/ViewProjection.hpp
               src/Renderer/DefaultRenderer.cpp
               src/Renderer/Transform.cpp
               src/Renderer/Vertex2D.cpp

               include/zgraphics2D/Renderer/Buffers/Buffer.hpp
               include/zgraphics2D/Renderer/Buffers/Buffer.inl
               include/zgraphics2D/Renderer/Buffers/IndexBuffer.hpp
               include/zgraphics2D/Renderer/Buffers/IndexBuffer.inl
               include/zgraphics2D/Renderer/Buffers/VertexArray.hpp
               include/zgraphics2D/Renderer/Buffers/VertexArray.inl
               include/zgraphics2D/Renderer/Buffers/VertexBuffer.hpp
               include/zgraphics2D/Renderer/Buffers/VertexLayout.hpp
               include/zgraphics2D/Renderer/Buffers/VertexLayout.inl
               src/Renderer/Buffers/Buffer.cpp
               src/Renderer/Buffers/IndexBuffer.cpp
               src/Renderer/Buffers/VertexBuffer.cpp
               src/Renderer/Buffers/VertexLayout.cpp
               src/Renderer/Buffers/VertexArray.cpp
               )

# src/Resources
TARGET_SOURCES(zgraphics PRIVATE
               include/zgraphics2D/Resources/Shader.hpp
               include/zgraphics2D/Resources/Shader.inl
               include/zgraphics2D/Resources/Texture.hpp
               include/zgraphics2D/Resources/Texture.inl
               src/Resources/Shader.cpp
               src/Resources/Texture.cpp
               )

# src/Text
TARGET_SOURCES(zgraphics PRIVATE
               include/zgraphics2D/Text/Font.hpp
               include/zgraphics2D/Text/Font.inl
               include/zgraphics2D/Text/Glyph.hpp
               include/zgraphics2D/Text/Glyph.inl
               include/zgraphics2D/Text/Encoding.hpp
               include/zgraphics2D/Text/BitmapFont.hpp
               include/zgraphics2D/Text/BitmapFont.inl
               src/Text/Font.cpp
               src/Text/Glyph.cpp
               src/Text/BitmapFont.cpp
               )

# src/Window
TARGET_SOURCES(zgraphics PRIVATE
               include/zgraphics2D/Window/Window.hpp
               include/zgraphics2D/Window/Window.inl
               include/zgraphics2D/Window/WindowSettings.hpp
               include/zgraphics2D/Window/ContextSettings.hpp
               include/zgraphics2D/Window/FrameBufferSettings.hpp
               src/Window/Window.cpp

               include/zgraphics2D/Window/Event/FrameBufferResisedEvent.hpp
               include/zgraphics2D/Window/Event/FrameBufferResisedEvent.inl
               src/Window/Event/FrameBufferResisedEvent.cpp

               include/zgraphics2D/Window/Event/WindowEvent.hpp
               include/zgraphics2D/Window/Event/WindowEvent.inl
               include/zgraphics2D/Window/Event/WindowMovedEvent.hpp
               include/zgraphics2D/Window/Event/WindowMovedEvent.inl
               include/zgraphics2D/Window/Event/WindowClosedEvent.hpp
               include/zgraphics2D/Window/Event/WindowScaledEvent.hpp
               include/zgraphics2D/Window/Event/WindowScaledEvent.inl
               include/zgraphics2D/Window/Event/WindowFocusedEvent.hpp
               include/zgraphics2D/Window/Event/WindowFocusedEvent.inl
               include/zgraphics2D/Window/Event/WindowResisedEvent.hpp
               include/zgraphics2D/Window/Event/WindowResisedEvent.inl
               include/zgraphics2D/Window/Event/WindowIconifiedEvent.hpp
               include/zgraphics2D/Window/Event/WindowIconifiedEvent.inl
               include/zgraphics2D/Window/Event/WindowMaximisedEvent.hpp
               include/zgraphics2D/Window/Event/WindowMaximisedEvent.inl
               include/zgraphics2D/Window/Event/WindowRefreshedEvent.hpp
               src/Window/Event/WindowEvent.cpp
               src/Window/Event/WindowMovedEvent.cpp
               src/Window/Event/WindowClosedEvent.cpp
               src/Window/Event/WindowScaledEvent.cpp
               src/Window/Event/WindowFocusedEvent.cpp
               src/Window/Event/WindowResisedEvent.cpp
               src/Window/Event/WindowIconifiedEvent.cpp
               src/Window/Event/WindowMaximisedEvent.cpp
               src/Window/Event/WindowRefreshedEvent.cpp
               )

# Dependencies
TARGET_SOURCES(zgraphics PRIVATE
               deps/glad/src/glad.c
               deps/glm/glm/detail/glm.cpp
               deps/stb/src/stb_image.c
               )

# Defines
TARGET_COMPILE_DEFINITIONS(zgraphics PRIVATE
                           $<$<CONFIG:Debug>:_DEBUG>
                           $<$<CONFIG:Release>:NDEBUG> 
                           )

# Include Dirs
TARGET_INCLUDE_DIRECTORIES(zgraphics PUBLIC
                           "${PROJECT_SOURCE_DIR}/ZGraphics2D/include"

                           "${PROJECT_SOURCE_DIR}/ZGraphics2D/deps/glad/include"
                           "${PROJECT_SOURCE_DIR}/ZGraphics2D/deps/glfw/include"
                           "${PROJECT_SOURCE_DIR}/ZGraphics2D/deps/glm"
                           "${PROJECT_SOURCE_DIR}/ZGraphics2D/deps/stb/include"
                           
                           ${FREETYPE_INCLUDE_DIR_freetype2}

                           "${PROJECT_BINARY_DIR}"
                           )

# System Include Dirs
TARGET_INCLUDE_DIRECTORIES(zgraphics SYSTEM PRIVATE
                           $<$<PLATFORM_ID:Linux,Darwin>:/usr/include>
                           $<$<PLATFORM_ID:Linux,Darwin>:/usr/local/include>
                           )

# Lib Dirs
TARGET_LINK_DIRECTORIES(zgraphics PRIVATE
                        $<$<PLATFORM_ID:Linux,Darwin>:/usr/lib>
                        $<$<PLATFORM_ID:Linux,Darwin>:/usr/local/lib>
                        )

# Linking
TARGET_LINK_LIBRARIES(zgraphics PRIVATE
                      zengine
                      glfw

                      Threads::Threads
                      Freetype::Freetype
                      OpenGL::GL

                      ${CMAKE_DL_LIBS}
                      $<$<PLATFORM_ID:Linux>:X11::X11>

                      "$<$<PLATFORM_ID:Darwin>:-framework Cocoa>"
                      "$<$<PLATFORM_ID:Darwin>:-framework IOKit>"
                      )

