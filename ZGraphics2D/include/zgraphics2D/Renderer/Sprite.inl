inline glm::vec2 zg::Sprite::getSize() const noexcept
{
   return m_size;
}

inline zg::Texture const* zg::Sprite::getTexture() const noexcept
{
   return m_texture;
}

inline size_t zg::Sprite::getVertexCount() const noexcept
{
   return 4;
}

inline zg::Vertex const* zg::Sprite::getVertex(size_t index) const noexcept
{
   ZE_ASSERT(index <= getVertexCount(), "Out of bound !");
   return &m_vertices[index];
}

