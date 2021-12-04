/**
 * Cube.hpp
 * 31 Oct 2021
 * Gaétan "The Aarnold" Jalin
 *
 * Copyright (C) 2020-2021 Gaétan Jalin
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 *    1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 *
 *    2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 *
 *    3. This notice may not be removed or altered from any source distribution.
 **/
#ifndef ZG_CUBE_HPP
#define ZG_CUBE_HPP

#include "zgraphics2D/defines.hpp"

#include "zgraphics2D/Renderable/Renderable.hpp"
#include "zgraphics2D/Renderer/Vertex2D.hpp"
#include "zgraphics2D/Resources/Texture.hpp"
#include "zgraphics2D/Renderer/Transform.hpp"

namespace zg
{
   class ZG_API Cube : public Renderable, public Transform
   {
   public:
      constexpr size_t getVertexCount() const noexcept override;
      Vertex const* getVertex(size_t index) const noexcept override;
      constexpr size_t getElementCount() const noexcept override;
      unsigned int* getElements() const noexcept override;

      void setSize(glm::vec3 size) noexcept;
      glm::vec3 getSize() const noexcept;

      constexpr size_t getTextureCount() const noexcept override;
      void setTexture(Texture const* texture) noexcept;
      Texture const* getTexture(size_t index) const noexcept override;

      Cube(glm::vec3 size);

   private:
      Texture const* m_texture;
      glm::vec3 m_size;
      Vertex2D m_vertices[24];
   };
}

#include "Cube.inl"

#endif /* ZG_CUBE_HPP */
