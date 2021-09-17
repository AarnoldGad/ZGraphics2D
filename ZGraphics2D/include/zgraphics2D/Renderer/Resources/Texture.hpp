/**
 * Texture.hpp
 * 8 Sep 2021
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
#ifndef ZG_TEXTURE_HPP
#define ZG_TEXTURE_HPP

#include "zgraphics2D/zgmacros.hpp"

#include "zgraphics2D/Common/Image.hpp"

namespace zg
{
   class ZG_API Texture
   {
   public:
      static Texture const Null;

      void loadFile(std::filesystem::path const& file);
      void loadImage(Image const& image);
      void loadData(uint8_t const* data, glm::ivec2 size, Image::Format format);

      unsigned int getHandle() const noexcept;
      glm::ivec2 getSize() const noexcept;

      static void Bind(Texture const& texture) noexcept;
      void bind() const noexcept;

      Texture();
      ~Texture();

   private:
      unsigned int m_texture;
      glm::ivec2 m_size;
   };
}

#include "Texture.inl"

#endif /* ZG_TEXTURE_HPP */
