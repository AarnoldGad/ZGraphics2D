/**
 * Buffer.hpp
 * 13 Sep 2021
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
#ifndef ZG_BUFFER_HPP
#define ZG_BUFFER_HPP

#include "zgraphics2D/defines.hpp"

namespace zg
{
   class ZG_API Buffer
   {
   public:
      enum class Usage : unsigned int
      {
         Static = 0,
         Dynamic,
      };

      void resize(size_t size);
      void setData(size_t size, void const* data);
      void setSubData(ptrdiff_t offset, size_t size, void const* data);

      template<typename BufferType>
      BufferType* map();
      void unmap();

      unsigned int getHandle() const noexcept;

      void bind() const noexcept;
      void unbind() const noexcept;

      // TODO remove/replace GLenum
      explicit Buffer(GLenum bufferType, Usage usage);
      ~Buffer();

   protected:
      unsigned int m_buffer;
      GLenum m_bufferType;
      Usage m_usage;
   };
}

#include "Buffer.inl"

#endif /* ZG_BUFFER_HPP */
