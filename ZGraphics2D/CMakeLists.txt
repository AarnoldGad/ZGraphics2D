ADD_LIBRARY(zgraphics SHARED)

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

# src/Camera
TARGET_SOURCES(zgraphics PRIVATE
               src/Camera/Camera.cpp
               src/Camera/FPSCamera.cpp
               src/Camera/OrthographicCamera.cpp
               )

# src/Common
TARGET_SOURCES(zgraphics PRIVATE
               src/Common/Image.cpp
               )

# src/Engine
TARGET_SOURCES(zgraphics PRIVATE
               src/Engine/GraphicsEngine.cpp
               )

# src/Input
TARGET_SOURCES(zgraphics PRIVATE
               src/Input/Joystick.cpp
               src/Input/Keyboard.cpp
               src/Input/Mouse.cpp

               src/Input/Event/KeyEvent.cpp
               src/Input/Event/KeyPressedEvent.cpp
               src/Input/Event/KeyReleasedEvent.cpp
               src/Input/Event/KeyRepeatedEvent.cpp

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
               src/Renderable/Sprite.cpp
               src/Renderable/Cube.cpp
               )

# src/Renderer
TARGET_SOURCES(zgraphics PRIVATE
               src/Renderer/DefaultRenderer.cpp
               src/Renderer/Transform.cpp
               src/Renderer/Vertex2D.cpp

               src/Renderer/Buffers/Buffer.cpp
               src/Renderer/Buffers/IndexBuffer.cpp
               src/Renderer/Buffers/VertexBuffer.cpp
               src/Renderer/Buffers/VertexLayout.cpp
               src/Renderer/Buffers/VertexArray.cpp
               )

# src/Resources
TARGET_SOURCES(zgraphics PRIVATE
               src/Resources/Shader.cpp
               src/Resources/Texture.cpp
               )

# src/Text
TARGET_SOURCES(zgraphics PRIVATE
               src/Text/Font.cpp
               src/Text/Glyph.cpp
               src/Text/BitmapFont.cpp
               )

# src/Window
TARGET_SOURCES(zgraphics PRIVATE
               src/Window/Window.cpp

               src/Window/Event/FrameBufferResisedEvent.cpp

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

