inline unsigned int zg::Texture::getHandle() const noexcept
{
   return m_texture;
}

inline glm::ivec2 zg::Texture::getSize() const noexcept
{
   return m_size;
}

inline ze::ResourceLoader<zg::Texture>::ResourceLoader(zg::Texture* texture)
   : m_texture(texture) {}

inline Status ze::ResourceLoader<zg::Texture>::loadFile(std::filesystem::path const& file)
{
   auto const& searchPaths = ze::ResourceManager<zg::Texture>::GetSearchPaths();
   
   using FilePath = std::optional<std::filesystem::path>;
   FilePath textureFile = ze::FileUtils::Search(searchPaths, file);

   if (textureFile)
      return m_texture->loadFile(textureFile.value());

   GFX_LOG_ERROR("Texture not found : {}", file);

   return Status::Error;
}

inline Status ze::ResourceLoader<zg::Texture>::loadImage(zg::Image const& image)
{
   return m_texture->loadImage(image);
}

inline Status ze::ResourceLoader<zg::Texture>::loadData(uint8_t const* data, glm::ivec2 size, zg::Image::Format format)
{
   return m_texture->loadData(data, size, format);
}

