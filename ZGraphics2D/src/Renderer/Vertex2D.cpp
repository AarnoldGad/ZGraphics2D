#include "zgraphics2D/Renderer/Vertex2D.hpp"

namespace zg
{
   Vertex2D::Vertex2D(glm::vec3 pos, glm::vec2 uv)
      : m_pos(pos), m_uv(uv) {}

   void const* Vertex2D::getLocationData(unsigned int index) const noexcept
   {
      switch (index)
      {
         case 0:
            return glm::value_ptr(m_pos);
         case 1:
            return glm::value_ptr(m_uv);
         default:
            return nullptr;
      }
   }

   void Vertex2D::setPosition(glm::vec3 pos) noexcept
   {
      m_pos = pos;
   }

   void Vertex2D::setTextureCoordinates(glm::vec2 uv) noexcept
   {
      m_uv = uv;
   }
}
