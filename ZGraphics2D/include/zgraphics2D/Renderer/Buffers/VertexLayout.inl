template<typename DataType>
inline void zg::VertexLayout::add([[maybe_unused]] unsigned int count, [[maybe_unused]] bool normalised) noexcept
{
   ZE_ASSERT(false, "Unknown data type !");
}

template<>
inline void zg::VertexLayout::add<char>(unsigned int count, bool normalised) noexcept
{
   add(GL_BYTE, sizeof(char), count, normalised);
}

template<>
inline void zg::VertexLayout::add<unsigned char>(unsigned int count, bool normalised) noexcept
{
   add(GL_UNSIGNED_BYTE, sizeof(unsigned char), count, normalised);
}

template<>
inline void zg::VertexLayout::add<short>(unsigned int count, bool normalised) noexcept
{
   add(GL_SHORT, sizeof(short), count, normalised);
}

template<>
inline void zg::VertexLayout::add<unsigned short>(unsigned int count, bool normalised) noexcept
{
   add(GL_UNSIGNED_SHORT, sizeof(unsigned short), count, normalised);
}

template<>
inline void zg::VertexLayout::add<int>(unsigned int count, bool normalised) noexcept
{
   add(GL_INT, sizeof(int), count, normalised);
}

template<>
inline void zg::VertexLayout::add<unsigned int>(unsigned int count, bool normalised) noexcept
{
   add(GL_UNSIGNED_INT, sizeof(unsigned int), count, normalised);
}

template<>
inline void zg::VertexLayout::add<float>(unsigned int count, bool normalised) noexcept
{
   add(GL_FLOAT, sizeof(float), count, normalised);
}

template<>
inline void zg::VertexLayout::add<glm::vec2>([[maybe_unused]] unsigned int count, bool normalised) noexcept
{
   add(GL_FLOAT, sizeof(float), 2, normalised);
}

template<>
inline void zg::VertexLayout::add<glm::vec3>([[maybe_unused]] unsigned int count, bool normalised) noexcept
{
   add(GL_FLOAT, sizeof(float), 3, normalised);
}

template<>
inline void zg::VertexLayout::add<glm::vec4>([[maybe_unused]] unsigned int count, bool normalised) noexcept
{
   add(GL_FLOAT, sizeof(float), 4, normalised);
}

inline std::vector<zg::VertexLayout::Location> const& zg::VertexLayout::getLayout() const noexcept
{
   return m_locations;
}

inline unsigned int zg::VertexLayout::getStride() const noexcept
{
   return m_totalSize;
}
