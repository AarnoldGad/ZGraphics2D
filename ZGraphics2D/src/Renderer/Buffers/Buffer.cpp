#include "zgraphics2D/Renderer/Buffers/Buffer.hpp"

#include <zengine/Memory/New.hpp>

namespace zg
{
   Buffer::Buffer(GLenum bufferType, Usage usage)
      : m_buffer(0), m_bufferType(bufferType), m_usage(usage)
   {
      glGenBuffers(1, &m_buffer);
   }

   void Buffer::setData(ptrdiff_t size, void const* data)
   {
      bind();
      glBufferData(m_bufferType, size, data, m_usage == Usage::Static ? GL_STATIC_DRAW : GL_DYNAMIC_DRAW);
   }

   void Buffer::bind() const noexcept
   {
      glBindBuffer(m_bufferType, m_buffer);
   }

   void Buffer::unbind() const noexcept
   {
      glBindBuffer(m_bufferType, 0);
   }

   Buffer::~Buffer()
   {
      glDeleteBuffers(1, &m_buffer);
   }
}
