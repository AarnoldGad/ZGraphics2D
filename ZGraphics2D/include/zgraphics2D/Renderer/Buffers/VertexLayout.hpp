/**
 * VertexLayout.hpp
 * 16 Sep 2021
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
#ifndef ZG_VERTEXLAYOUT_HPP
#define ZG_VERTEXLAYOUT_HPP

#include "zgraphics2D/zgmacros.hpp"

#include <vector>

namespace zg
{
   class ZG_API VertexLayout
   {
   public:
      struct Location
      {
         unsigned int index;
         unsigned int size;
         unsigned int type;
         unsigned int count;
         unsigned int offset;
         bool normalised;
      };

      template<typename DataType>
      void add(unsigned int count, bool normalised = false) noexcept;
      std::vector<Location> const& getLayout() const noexcept;
      unsigned int getStride() const noexcept;

      VertexLayout();

   private:
      void add(unsigned int type, unsigned int size, unsigned int count, bool normalised) noexcept;

   private:

      std::vector<Location> m_locations;
      mutable unsigned int m_totalSize;
   };
}

#include "VertexLayout.inl"

#endif /* ZG_VERTEXLAYOUT_HPP */
