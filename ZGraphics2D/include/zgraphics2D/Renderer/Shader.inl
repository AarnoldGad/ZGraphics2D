#include <zengine/Memory/New.hpp>

inline unsigned int zg::Shader::getHandle() const noexcept
{
   return m_program;
}

#include <zengine/Memory/NewOff.hpp>
