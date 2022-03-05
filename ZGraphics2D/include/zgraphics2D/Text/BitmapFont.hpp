/**
 * BitmapFont.hpp
 * 19 Nov 2021
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
#ifndef ZG_BITMAPFONT_HPP
#define ZG_BITMAPFONT_HPP

#include "zgraphics2D/defines.hpp"

#include "zgraphics2D/Text/Font.hpp"
#include "zgraphics2D/Text/Encoding.hpp"
#include "zgraphics2D/Common/Image.hpp"

namespace zg
{
   class ZG_API BitmapFont : public Font
   {
   public:
      Glyph const& getGlyph(uint32_t index) const override;
      Texture const* getAtlas() const noexcept;

      void load(std::filesystem::path const& path, glm::ivec2 glyphCount,
                Encoding encoding = Encoding::Latin1, unsigned int start = 32);

      BitmapFont() = default;

   private:
      std::map<unsigned int, Glyph> m_glyphs;
      Texture m_atlas;
   };
}

#include "BitmapFont.inl"

#endif /* ZG_BITMAPFONT_HPP */
