/**
 * KeyReleasedEvent.hpp
 * 30 Jun 2021
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
#ifndef ZG_KEYRELEASEDEVENT_HPP
#define ZG_KEYRELEASEDEVENT_HPP

#include "zgraphics2D/zgmacros.hpp"

#include "zgraphics2D/Input/Event/KeyEvent.hpp"

namespace zg
{
   class ZE_API KeyReleasedEvent : public KeyEvent
   {
   public:
      std::string toString() const override;

      KeyReleasedEvent(Window* window, Keyboard::Key key, int scancode, uint32_t modifiers);
   };
}

#endif // ZG_KEYRELEASEDEVENT
