#include "zgpch.hpp"

#include "zgraphics2D/Text/Font.hpp"

namespace zg
{
   Font::Font()
      : m_encoding(Encoding::Unkown) {}

   void Font::setEncoding(Encoding encoding) noexcept
   {
      m_encoding = encoding;
   }
}
