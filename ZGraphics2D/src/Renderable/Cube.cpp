#include "zgpch.hpp"

#include "zgraphics2D/Renderable/Cube.hpp"

namespace zg
{
   Cube::Cube(glm::vec3 size)
      : m_size(size)
   {
      setSize(size);
   }

   void Cube::setSize(glm::vec3 size) noexcept
   {
      m_size = size;
      
      m_vertices[0]  = Vertex2D({ 0.f   , 0.f   , 0.f    }, { 0.f, 0.f});
      m_vertices[1]  = Vertex2D({ size.x, 0.f   , 0.f    }, { 1.f, 0.f});
      m_vertices[2]  = Vertex2D({ 0.f   , size.y, 0.f    }, { 0.f, 1.f});
      m_vertices[3]  = Vertex2D({ size.x, size.y, 0.f    }, { 1.f, 1.f});

      m_vertices[4]  = Vertex2D({ size.x, 0.f   , 0.f    }, { 0.f, 0.f});
      m_vertices[5]  = Vertex2D({ size.x, 0.f   , size.z }, { 1.f, 0.f});
      m_vertices[6]  = Vertex2D({ size.x, size.y, 0.f    }, { 0.f, 1.f});
      m_vertices[7]  = Vertex2D({ size.x, size.y, size.z }, { 1.f, 1.f});

      m_vertices[8]  = Vertex2D({ size.x, 0.f   , size.z }, { 0.f, 0.f});
      m_vertices[9]  = Vertex2D({ 0.f   , 0.f   , size.z }, { 1.f, 0.f});
      m_vertices[10] = Vertex2D({ size.x, size.y, size.z }, { 0.f, 1.f});
      m_vertices[11] = Vertex2D({ 0.f   , size.y, size.z }, { 1.f, 1.f});

      m_vertices[12] = Vertex2D({ 0.f   , 0.f   , size.z }, { 0.f, 0.f});
      m_vertices[13] = Vertex2D({ 0.f   , 0.f   , 0.f    }, { 1.f, 0.f});
      m_vertices[14] = Vertex2D({ 0.f   , size.y, size.z }, { 0.f, 1.f});
      m_vertices[15] = Vertex2D({ 0.f   , size.y, 0.f    }, { 1.f, 1.f});

      m_vertices[16] = Vertex2D({ 0.f   , 0.f   , size.z }, { 0.f, 0.f});
      m_vertices[17] = Vertex2D({ size.x, 0.f   , size.z }, { 1.f, 0.f});
      m_vertices[18] = Vertex2D({ 0.f   , 0.f   , 0.f    }, { 0.f, 1.f});
      m_vertices[19] = Vertex2D({ size.x, 0.f   , 0.f    }, { 1.f, 1.f});

      m_vertices[20] = Vertex2D({ 0.f   , size.y, 0.f    }, { 0.f, 0.f});
      m_vertices[21] = Vertex2D({ size.x, size.y, 0.f    }, { 1.f, 0.f});
      m_vertices[22] = Vertex2D({ 0.f   , size.y, size.z }, { 0.f, 1.f});
      m_vertices[23] = Vertex2D({ size.x, size.y, size.z }, { 1.f, 1.f});
   }

   void Cube::setTexture(Texture const* texture) noexcept
   {
      m_texture = texture;
   }
}
