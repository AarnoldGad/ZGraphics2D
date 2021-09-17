#include <zengine/Memory/New.hpp>

inline unsigned int zg::Buffer::getHandle() const noexcept
{
   return m_buffer;
}

#include <zengine/Memory/NewOff.hpp>
