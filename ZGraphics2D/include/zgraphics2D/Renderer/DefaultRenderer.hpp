/**
 * DefaultRenderer.hpp
 * 26 Oct 2021
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
#ifndef ZG_DEFAULTRENDERER_HPP
#define ZG_DEFAULTRENDERER_HPP

#include "zgraphics2D/defines.hpp"

#include "zgraphics2D/Renderer/Renderer.hpp"
#include "zgraphics2D/Renderer/VertexLayout.hpp"
#include "zgraphics2D/Renderer/Buffers/VertexArray.hpp"
#include "zgraphics2D/Renderer/Buffers/VertexBuffer.hpp"
#include "zgraphics2D/Renderer/Buffers/IndexBuffer.hpp"
#include "zgraphics2D/Renderer/ViewProjection.hpp"
#include "zgraphics2D/Renderable/Renderable.hpp"

#include <vector>

namespace zg
{
   // TODO Ineffective renderer
   class ZG_API DefaultRenderer : public Renderer
   {
   public:
      void setLayout(VertexLayout const& layout);
      void setViewProjection(ViewProjection const* viewProjection) noexcept;

      void submit(Renderable const& object, glm::mat4 transform = {});
      void render(Shader& shader) override;

      DefaultRenderer() = default;

   private:
      VertexArray m_vao;
      VertexBuffer m_vbo;
      IndexBuffer m_ebo;

      ViewProjection const* m_viewProjection;
      std::map<Renderable const*, glm::mat4> m_objects;
   };
}

#endif /* ZG_DEFAULTRENDERER_HPP */
