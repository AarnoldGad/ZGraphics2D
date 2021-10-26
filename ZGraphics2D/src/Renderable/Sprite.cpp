#include "zgpch.hpp"

#include "zgraphics2D/Renderable/Sprite.hpp"

namespace zg
{
   Sprite::Sprite(glm::vec2 size, Texture const* texture)
      : m_size(size), m_texture(texture)
   {
      setSize(size);
   }

   void Sprite::setSize(glm::vec2 size) noexcept
   {
      m_size = size;
      m_vertices[0] = Vertex2D({ 0.f   , 0.f   , 0.f }, { 0.f, 0.f});
      m_vertices[1] = Vertex2D({ size.x, 0.f   , 0.f }, { 1.f, 0.f});
      m_vertices[2] = Vertex2D({ 0.f   , size.y, 0.f }, { 0.f, 1.f});
      m_vertices[3] = Vertex2D({ size.x, size.y, 0.f }, { 1.f, 1.f});
   }

   void Sprite::setTexture(Texture const* texture) noexcept
   {
      m_texture = texture;
   }
}
