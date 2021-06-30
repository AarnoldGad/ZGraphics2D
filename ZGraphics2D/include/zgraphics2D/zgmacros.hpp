#ifndef ZG_MACROS_HPP
#define ZG_MACROS_HPP

#include <zengine/zemacros.hpp>

#define ZG_VERSION_MAJOR 0
#define ZG_VERSION_MINOR 21
#define ZG_VERSION_PATCH 6
#define ZG_VERSION_REV 30

#define GFX_LOG_INFO(...)     ::zg::GraphicsEngine::UseGraphicsLogger().logLine(::ze::Level::Info    , __VA_ARGS__)
#define GFX_LOG_DEBUG(...)    ::zg::GraphicsEngine::UseGraphicsLogger().logLine(::ze::Level::Debug   , __VA_ARGS__)
#define GFX_LOG_WARN(...)     ::zg::GraphicsEngine::UseGraphicsLogger().logLine(::ze::Level::Warn    , __VA_ARGS__)
#define GFX_LOG_ERROR(...)    ::zg::GraphicsEngine::UseGraphicsLogger().logLine(::ze::Level::Error   , __VA_ARGS__)
#define GFX_LOG_CRITICAL(...) ::zg::GraphicsEngine::UseGraphicsLogger().logLine(::ze::Level::Critical, __VA_ARGS__)

#include <zengine/zengine.hpp>
#include <glad/glad.h>
#define GLFW_DLL
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#endif // ZG_MACROS_HPP
