#include "zgpch.hpp"

#include "zgraphics2D/Renderer/Buffers/Buffer.hpp"

namespace zg
{
   Buffer::Buffer(GLenum bufferType, Usage usage)
      : m_buffer(0), m_bufferType(bufferType), m_usage(usage)
   {
      glGenBuffers(1, &m_buffer);
   }

   void Buffer::resize(size_t size)
   {
      bind();
      glBufferData(m_bufferType, size, nullptr, m_usage == Usage::Static ? GL_STATIC_DRAW : GL_DYNAMIC_DRAW);
   }

   void Buffer::setData(size_t size, void const* data)
   {
      bind();
      glBufferData(m_bufferType, size, data, m_usage == Usage::Static ? GL_STATIC_DRAW : GL_DYNAMIC_DRAW);
   }

   void Buffer::setSubData(ptrdiff_t offset, size_t size, void const* data)
   {
      bind();
      glBufferSubData(m_bufferType, offset, size, data);
   }

   void Buffer::bind() const noexcept
   {
      glBindBuffer(m_bufferType, m_buffer);
   }

   void Buffer::unbind() const noexcept
   {
      glBindBuffer(m_bufferType, 0);
   }

   void Buffer::unmap()
   {
      bind();
      glUnmapBuffer(m_bufferType);
   }

   Buffer::~Buffer()
   {
      glDeleteBuffers(1, &m_buffer);
   }
}
