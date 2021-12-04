inline zg::Glyph const& zg::BitmapFont::getGlyph(unsigned int index) const
{
   try
   {
      return m_glyphs.at(index);
   }
   catch (std::out_of_range const& e)
   {
      return m_glyphs.begin()->second;
   }
}

inline zg::Texture const* zg::BitmapFont::getAtlas() const noexcept
{
   return &m_atlas;
}
