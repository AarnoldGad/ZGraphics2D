#include "zgpch.hpp"

#include "zgraphics2D/Renderer/Buffers/IndexBuffer.hpp"

namespace zg
{
   static_assert(sizeof(unsigned char ) == sizeof(GLubyte ));
   static_assert(sizeof(unsigned short) == sizeof(GLushort));
   static_assert(sizeof(unsigned int  ) == sizeof(GLuint  ));

   IndexBuffer::IndexBuffer(Type type)
      : Buffer(GL_ELEMENT_ARRAY_BUFFER, Buffer::Usage::Static), m_type(type) {}
}
