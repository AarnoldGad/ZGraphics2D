#include "zgpch.hpp"

#include "zgraphics2D/Renderer/Resources/Shader.hpp"

#include "zgraphics2D/Engine/GraphicsEngine.hpp"

#include <glm/gtc/type_ptr.hpp>

#define CHECK_PROGRAM \
   int currentProgram; \
   glGetIntegerv(GL_CURRENT_PROGRAM, &currentProgram); \
   if (static_cast<unsigned int>(currentProgram) != m_program) \
   GFX_LOG_DEBUG("Currently bound program is different !"); \

namespace zg
{
   Shader::Shader()
      : m_program(0) {}

   Shader::Shader(std::filesystem::path const& vertex, std::filesystem::path const& fragment)
      : m_program(0)
   {
      loadFile(vertex, fragment);
   }

   Shader::Shader(char const* vertex, char const* fragment)
      : m_program(0)
   {
      loadSource(vertex, fragment);
   }

   void Shader::loadFile(std::filesystem::path const& vertexFile, std::filesystem::path const& fragmentFile)
   {
      std::optional<std::string> vertexSource   = ze::FileUtils::GetFileContent(vertexFile);
      std::optional<std::string> fragmentSource = ze::FileUtils::GetFileContent(fragmentFile);

      loadSource(vertexSource   ? vertexSource->c_str()   : (GFX_LOG_ERROR("No vertex shader loaded !")  , ""),
                 fragmentSource ? fragmentSource->c_str() : (GFX_LOG_ERROR("No fragment shader loaded !"), ""));
   }

   void Shader::loadSource(char const* vertexSource, char const* fragmentSource)
   {
      resetProgram();

      unsigned int vertexShader = addShader(GL_VERTEX_SHADER, vertexSource);
      unsigned int fragmentShader = addShader(GL_FRAGMENT_SHADER, fragmentSource);

      if (!vertexShader || !fragmentShader) return;

      linkProgram();

      glDeleteShader(vertexShader);
      glDeleteShader(fragmentShader);
   }

   unsigned int Shader::addShader(unsigned int type, char const* source) noexcept
   {
      unsigned int shader = glCreateShader(type);

      //TODO OpenGL error handling
      glShaderSource(shader, 1, &source, nullptr);
      glCompileShader(shader);

      int success;
      glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
      if (!success)
      {
         char log[512];
         glGetShaderInfoLog(shader, 512, nullptr, log);
         GFX_LOG_ERROR("Fail to compile %s shader : %s",
                       (type == GL_VERTEX_SHADER ? "vertex" :
                       (type == GL_FRAGMENT_SHADER ? "fragment" : "unknown")),
                       log);

         glDeleteShader(shader);
         return 0;
      }

      glAttachShader(m_program, shader);

      return shader;
   }

   void Shader::linkProgram() noexcept
   {
      glLinkProgram(m_program);

      int success;
      glGetProgramiv(m_program, GL_LINK_STATUS, &success);
      if (!success)
      {
         char log[512];
         glGetProgramInfoLog(m_program, 512, NULL, log);
         GFX_LOG_ERROR("Fail to link shader program : %s", log);

         resetProgram();
      }
   }

   void Shader::setBoolean(std::string const& var, bool value)
   {
      setInteger(var, value);
   }

   void Shader::setInteger(std::string const& var, int value)
   {
      CHECK_PROGRAM;
      glUniform1i(getUniformLocation(var), value);
   }

   void Shader::setFloat(std::string const& var, float value)
   {
      CHECK_PROGRAM;
      glUniform1f(getUniformLocation(var), value);
   }

   void Shader::setVector2(std::string const& var, glm::vec2 value)
   {
      CHECK_PROGRAM;
      glUniform2f(getUniformLocation(var), value.x, value.y);
   }

   void Shader::setVector3(std::string const& var, glm::vec3 value)
   {
      CHECK_PROGRAM;
      glUniform3f(getUniformLocation(var), value.x, value.y, value.z);
   }

   void Shader::setVector4(std::string const& var, glm::vec4 value)
   {
      CHECK_PROGRAM;
      glUniform4f(getUniformLocation(var), value.x, value.y, value.z, value.w);
   }

   void Shader::setMatrix2(std::string const& var, glm::mat2 value, bool transpose)
   {
      CHECK_PROGRAM;
      glUniformMatrix2fv(getUniformLocation(var), 1, transpose ? GL_TRUE : GL_FALSE, glm::value_ptr(value));
   }

   void Shader::setMatrix3(std::string const& var, glm::mat3 value, bool transpose)
   {
      CHECK_PROGRAM;
      glUniformMatrix3fv(getUniformLocation(var), 1, transpose ? GL_TRUE : GL_FALSE, glm::value_ptr(value));
   }

   void Shader::setMatrix4(std::string const& var, glm::mat4 value, bool transpose)
   {
      CHECK_PROGRAM;
      glUniformMatrix4fv(getUniformLocation(var), 1, transpose ? GL_TRUE : GL_FALSE, glm::value_ptr(value));
   }

   void Shader::setIntegerArray(std::string const& var, int const* value, size_t count)
   {
      CHECK_PROGRAM;
      glUniform1iv(getUniformLocation(var), count, value);
   }

   void Shader::setFloatArray(std::string const& var, float const* value, size_t count)
   {
      CHECK_PROGRAM;
      glUniform1fv(getUniformLocation(var), count, value);
   }

   int Shader::getUniformLocation(std::string const& var) const noexcept
   {
      auto uniform = m_uniforms.find(var);
      if (uniform == m_uniforms.end())
      {
         int location = glGetUniformLocation(m_program, var.c_str());

         if (location == -1)
            GFX_LOG_ERROR("Fail to retrieve uniform location for %s !", var);
         else
            m_uniforms.insert(std::make_pair(var, location));

         return location;
      }

      return uniform->second;
   }

   void Shader::resetProgram() noexcept
   {
      if (m_program)
         glDeleteProgram(m_program);
      m_program = glCreateProgram();
   }

   void Shader::use()
   {
      glUseProgram(m_program);
   }

   Shader::~Shader()
   {
      if (m_program)
         glDeleteProgram(m_program);
   }
}
