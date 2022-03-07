#include "zgpch.hpp"

#include "zgraphics2D/Renderer/Buffers/VertexBuffer.hpp"

namespace zg
{
   VertexBuffer::VertexBuffer()
      : Buffer(Buffer::Type::Vertex, Buffer::Usage::Static) {}
}
