inline unsigned int zg::Buffer::getHandle() const noexcept
{
   return m_buffer;
}

template<typename BufferType>
inline BufferType* zg::Buffer::map()
{
   bind();
   return reinterpret_cast<BufferType*>(glMapBuffer(m_bufferType, GL_WRITE_ONLY));
}

