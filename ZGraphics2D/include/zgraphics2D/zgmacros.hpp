#ifndef ZG_MACROS_HPP
#define ZG_MACROS_HPP

#include <zengine/zemacros.hpp>
#include <zgraphics2D/zgplatform.hpp>

#define ZG_VERSION_MAJOR 0
#define ZG_VERSION_MINOR 21
#define ZG_VERSION_PATCH 6
#define ZG_VERSION_REV 30

#define GFX_LOG_INFO(...)     ::zg::GraphicsEngine::UseGraphicsLogger().info().logLine(__VA_ARGS__)
#define GFX_LOG_DEBUG(...)    ::zg::GraphicsEngine::UseGraphicsLogger().debug().logLine(__VA_ARGS__)
#define GFX_LOG_WARN(...)     ::zg::GraphicsEngine::UseGraphicsLogger().warn().logLine(__VA_ARGS__)
#define GFX_LOG_ERROR(...)    ::zg::GraphicsEngine::UseGraphicsLogger().error().logLine(__VA_ARGS__)
#define GFX_LOG_CRITICAL(...) ::zg::GraphicsEngine::UseGraphicsLogger().critical().logLine(__VA_ARGS__)

#include <zengine/zengine.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <stb_image/stb_image.h>

#endif // ZG_MACROS_HPP
