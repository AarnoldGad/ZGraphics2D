inline unsigned int zg::Shader::getHandle() const noexcept
{
   return m_program;
}

inline ze::ResourceLoader<zg::Shader>::ResourceLoader(zg::Shader* shader)
   : m_shader(shader) {}

inline Status ze::ResourceLoader<zg::Shader>::loadSource(char const* vertex, char const* fragment)
{
   return m_shader->loadSource(vertex, fragment);
}

inline Status ze::ResourceLoader<zg::Shader>::loadFile(std::filesystem::path const& vertex,
                                                       std::filesystem::path const& fragment)
{
   auto const& searchPaths = ze::ResourceManager<zg::Shader>::GetSearchPaths();
   
   using FilePath = std::optional<std::filesystem::path>;
   FilePath vertexFile = ze::FileUtils::Search(searchPaths, vertex);
   FilePath fragmentFile = ze::FileUtils::Search(searchPaths, fragment);

   if (vertexFile && fragmentFile)
      return m_shader->loadFile(vertexFile.value(), fragmentFile.value());

   if (!vertexFile)
      GFX_LOG_ERROR("File not found : {}", vertex);
   if (!fragmentFile)
      GFX_LOG_ERROR("File not found : {}", fragment);

   return Status::Error;
}

