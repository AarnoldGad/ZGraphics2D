#include "zgpch.hpp"

#include "zgraphics2D/Input/Event/MouseDroppedEvent.hpp"

namespace zg
{
   MouseDroppedEvent::MouseDroppedEvent(Window* window, glm::ivec2 pos, size_t count, char const* paths[])
      : MouseEvent(window, pos), m_paths{}
   {
      for (size_t i = 0; i < count; i++)
         m_paths.push_back(paths[i]);
   }

   std::string MouseDroppedEvent::toString() const
   {
      std::stringstream debugStr;

      debugStr << "Mouse dropped on (" << m_pos.x << ", " << m_pos.y << ")" << std::endl;

      std::for_each(m_paths.begin(), m_paths.end(),
                    [&debugStr](std::filesystem::path const& file) { debugStr << "\t" << file.string() << std::endl; });

      return debugStr.str();
   }
}
