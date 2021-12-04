#include "zgpch.hpp"

#include "zgraphics2D/Text/Glyph.hpp"

namespace zg
{
   Glyph::Glyph()
      : m_rect{}, m_size{}, m_bearing{}, m_advance{} {}

   Glyph::Glyph(glm::vec4 rect, glm::ivec2 size, glm::ivec2 bearing, unsigned int advance)
      : m_rect(rect), m_size(size), m_bearing(bearing), m_advance(advance)
   {}
}
