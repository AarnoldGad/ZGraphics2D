inline size_t zg::Cube::getVertexCount() const noexcept
{
   return sizeof(m_vertices) / sizeof(Vertex2D);
}

inline zg::Vertex const* zg::Cube::getVertex(size_t index) const noexcept
{
   ZE_ASSERT(index <= getVertexCount(), "Out of bound !");
   return &m_vertices[index];
}

inline size_t zg::Cube::getElementCount() const noexcept
{
   return 36;
}

inline unsigned int* zg::Cube::getElements() const noexcept
{
   static unsigned int elements[] =
   {
      0, 1, 2, // 1st face
      1, 2, 3,

      4, 5, 6, // 2d face
      5, 6, 7,

      8,  9, 10, // 3rd face
      9, 10, 11,

      12, 13, 14, // 4th face
      13, 14, 15,

      16, 17, 18, // 5th face
      17, 18, 19,

      20, 21, 22, // 6th face
      21, 22, 23
   };
   return elements;
}

inline glm::vec3 zg::Cube::getSize() const noexcept
{
   return m_size;
}

inline size_t zg::Cube::getTextureCount() const noexcept
{
   return 1;
}

inline zg::Texture const* zg::Cube::getTexture(size_t index) const noexcept
{
   return m_texture;
}
