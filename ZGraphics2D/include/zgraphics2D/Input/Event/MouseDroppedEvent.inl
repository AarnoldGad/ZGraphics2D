inline std::vector<std::filesystem::path> const& zg::MouseDroppedEvent::getPaths() const noexcept
{
   return m_paths;
}

inline std::filesystem::path zg::MouseDroppedEvent::getPath(size_t index) const
{
   return m_paths.at(index);
}

inline size_t zg::MouseDroppedEvent::getPathCount() const noexcept
{
   return m_paths.size();
}
