/**
 * WindowResisedEvent.hpp
 * 7 Jul 2021
 * Gaétan "The Aarnold" Jalin
 *
 * Copyright (C) 2020-2021 Gaétan Jalin
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 *    1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 *
 *    2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 *
 *    3. This notice may not be removed or altered from any source distribution.
 **/
#ifndef ZG_WINDOWRESISEDEVENT_HPP
#define ZG_WINDOWRESISEDEVENT_HPP

#include "zgraphics2D/defines.hpp"

#include "zgraphics2D/Window/Event/WindowEvent.hpp"

namespace zg
{
   class ZG_API WindowResisedEvent : public WindowEvent
   {
   public:
      glm::ivec2 getSize() const noexcept;
      glm::ivec2 getOffset() const noexcept;

      std::string toString() const override;

      WindowResisedEvent(Window* window, glm::ivec2 newSize, glm::ivec2 oldSize);
   private:
      glm::ivec2 const m_size;
      glm::ivec2 const m_offset;
   };
}

#include "WindowResisedEvent.inl"

#endif // ZG_WINDOWRESISEDEVENT_HPP
