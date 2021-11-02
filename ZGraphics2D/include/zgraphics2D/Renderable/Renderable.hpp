/**
 * Renderable.hpp
 * 23 Sep 2021
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
#ifndef ZE_RENDERABLE_HPP
#define ZE_RENDERABLE_HPP

#include "zgraphics2D/defines.hpp"

#include "zgraphics2D/Renderer/Vertex.hpp"
#include "zgraphics2D/Renderer/Resources/Texture.hpp"

namespace zg
{
   class ZG_API Renderable
   {
   public:
      virtual size_t getVertexCount() const noexcept = 0;
      virtual Vertex const* getVertex(size_t index) const noexcept = 0;

      virtual size_t getElementCount() const noexcept = 0;
      virtual unsigned int* getElements() const noexcept = 0;

      virtual size_t getTextureCount() const noexcept = 0;
      virtual Texture const* getTexture(size_t index) const noexcept = 0;
   };
}

#endif /* ZE_RENDERABLE_HPP */
