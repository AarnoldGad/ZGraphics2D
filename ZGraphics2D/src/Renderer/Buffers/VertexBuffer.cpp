#include "zgraphics2D/Renderer/Buffers/VertexBuffer.hpp"

#include <zengine/Memory/New.hpp>

namespace zg
{
   VertexBuffer::VertexBuffer()
      : Buffer(GL_ARRAY_BUFFER, Buffer::Usage::Static) {}
}
