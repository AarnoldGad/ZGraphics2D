#include "zgpch.hpp"

#include "zgraphics2D/Text/BitmapFont.hpp"

namespace zg
{
   void BitmapFont::load(std::filesystem::path const& file, glm::ivec2 glyphCount, Encoding encoding, unsigned int start)
   {
      m_glyphs.clear();
      setEncoding(encoding);

      Image bitmap;
      bitmap.loadFile(file, Image::Format::Grey);
      m_atlas.loadImage(bitmap);

      glm::ivec2 glyphSize = bitmap.getSize() / glyphCount;
      size_t totalGlyphCount = glyphCount.x * glyphCount.y;

      for (unsigned int i = 0; i < totalGlyphCount; ++i)
      {
         glm::vec4 rect = { static_cast<float>((i % glyphCount.x) * glyphSize.x) / static_cast<float>(bitmap.getSize().x),
                            1.f - static_cast<float>((i / glyphCount.x + 1) * glyphSize.y) / static_cast<float>(bitmap.getSize().y),
                            static_cast<float>(glyphSize.x) / static_cast<float>(bitmap.getSize().x),
                            static_cast<float>(glyphSize.y) / static_cast<float>(bitmap.getSize().y) };
         m_glyphs.emplace(std::piecewise_construct,
                          std::forward_as_tuple(start + i),
                          std::forward_as_tuple(rect, glyphSize, glm::ivec2(), 0));
      }
   }
}
