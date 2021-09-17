#include "zgraphics2D/Renderer/Buffers/IndexBuffer.hpp"

#include <zengine/Memory/New.hpp>

namespace zg
{
   IndexBuffer::IndexBuffer(Type type)
      : Buffer(GL_ELEMENT_ARRAY_BUFFER, Buffer::Usage::Static), m_type(type) {}
}
