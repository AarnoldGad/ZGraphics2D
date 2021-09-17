#include <zengine/Memory/New.hpp>

inline zg::IndexBuffer::Type zg::IndexBuffer::getElementType() const noexcept
{
   return m_type;
}

#include <zengine/Memory/NewOff.hpp>
