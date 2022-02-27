#ifndef ZG_DEFINES_HPP
#define ZG_DEFINES_HPP

#include <zengine/defines.hpp>
#include "zgconfig.hpp"
#include "platform.hpp"

#define ZG_CONTEXT_LIB_GLFW
// TODO Abstract API (so it can be changed by Vulkan or DirectX)
//#define ZG_CONTEXT_API_OPENGL

#define GFX_LOG_INFO(...)     ::zg::GraphicsEngine::UseGraphicsLogger().info().logLine(__VA_ARGS__)
#define GFX_LOG_DEBUG(...)    ::zg::GraphicsEngine::UseGraphicsLogger().debug().logLine(__VA_ARGS__)
#define GFX_LOG_WARN(...)     ::zg::GraphicsEngine::UseGraphicsLogger().warn().logLine(__VA_ARGS__)
#define GFX_LOG_ERROR(...)    ::zg::GraphicsEngine::UseGraphicsLogger().error().logLine(__VA_ARGS__)
#define GFX_LOG_CRITICAL(...) ::zg::GraphicsEngine::UseGraphicsLogger().critical().logLine(__VA_ARGS__)

#include <zengine/zengine.hpp>

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/scalar_multiplication.hpp>

#endif // ZG_DEFINES_HPP
