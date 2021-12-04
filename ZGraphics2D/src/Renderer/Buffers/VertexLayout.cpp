#include "zgpch.hpp"

#include "zgraphics2D/Renderer/VertexLayout.hpp"

namespace zg
{
   VertexLayout::VertexLayout()
      : m_totalSize{} {}

   void zg::VertexLayout::add(unsigned int type, unsigned int size, unsigned int count, bool normalised) noexcept
   {
      m_locations.push_back({ static_cast<unsigned int>(m_locations.size()),
                              size * count, type, count, m_totalSize, normalised });
      m_totalSize += size * count;
   }
}
