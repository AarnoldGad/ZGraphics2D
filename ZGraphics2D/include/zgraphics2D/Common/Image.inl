inline uint8_t const* zg::Image::getData() const noexcept
{
   return m_data;
}

inline zg::Image::Format zg::Image::getFormat() const noexcept
{
   return m_format;
}

inline glm::ivec2 zg::Image::getSize() const noexcept
{
   return m_size;
}

inline zg::Image::operator bool() const noexcept
{
   return isLoaded();
}

inline bool zg::Image::isLoaded() const noexcept
{
   return m_data;
}

inline ze::ResourceLoader<zg::Image>::ResourceLoader(zg::Image* image)
   : m_image(image) {}

inline Status ze::ResourceLoader<zg::Image>::loadFile(std::filesystem::path const& file, zg::Image::Format format)
{
   auto const& searchPaths = ze::ResourceManager<zg::Image>::GetSearchPaths();
   
   using FilePath = std::optional<std::filesystem::path>;
   FilePath foundFile = ze::FileUtils::Search(searchPaths, file);

   if (!foundFile)
      return m_image->loadFile(foundFile.value(), format);

   GFX_LOG_ERROR("File not found : {}", file);
   return Status::Error;
}

