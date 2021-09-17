#include <zengine/Memory/New.hpp>

inline zg::VertexLayout const& zg::VertexArray::getLayout() const noexcept
{
   return m_layout;
}

#include <zengine/Memory/NewOff.hpp>
