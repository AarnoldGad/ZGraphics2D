#include "zgpch.hpp"

#include "zgraphics2D/Renderer/Buffers/VertexArray.hpp"

namespace zg
{
   VertexArray::VertexArray()
      : m_vao(0)
   {
      glGenVertexArrays(1, &m_vao);
   }

   void VertexArray::bind()
   {
      glBindVertexArray(m_vao);
   }

   void VertexArray::unbind()
   {
      glBindVertexArray(0);
   }

   void VertexArray::setLayout(VertexLayout const& layout)
   {
      bind();
      m_layout = layout;

      for (zg::VertexLayout::Location const& location : layout.getLayout())
      {
         glVertexAttribPointer(location.index, location.count, location.type,
                               location.normalised ? GL_TRUE : GL_FALSE, layout.getStride(),
                               reinterpret_cast<void*>(location.offset));
         glEnableVertexAttribArray(location.index);
      }
   }

   VertexArray::~VertexArray()
   {
      glDeleteVertexArrays(1, &m_vao);
   }
}
