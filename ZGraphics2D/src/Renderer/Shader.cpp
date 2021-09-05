#include "zgraphics2D/Renderer/Shader.hpp"

#include "zgraphics2D/Engine/GraphicsEngine.hpp"

#include <zengine/Memory/New.hpp>

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
