#include "zgpch.hpp"

#include "zgraphics2D/Renderer/Buffers/VertexBuffer.hpp"

namespace zg
{
   VertexBuffer::VertexBuffer()
      : Buffer(GL_ARRAY_BUFFER, Buffer::Usage::Static) {}
}
