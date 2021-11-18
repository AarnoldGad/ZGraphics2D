/**
 * View.hpp
 * 25 Oct 2021
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
#ifndef ZG_VIEW_HPP
#define ZG_VIEW_HPP

#include "zgraphics2D/defines.hpp"

#include "zgraphics2D/Renderer/Transforms/ViewProjection.hpp"

namespace zg
{
   class ZG_API View : public ViewProjection
   {
   public:
      glm::mat4 const& getView() const override;
      glm::mat4 const& getProjection() const override;

      void setSize(glm::vec2 size) noexcept;
      void setViewport(glm::vec4 viewport) noexcept;
      void setCentre(glm::vec2 pos) noexcept;
      void setRotation(ze::Angle angle) noexcept;

      void move(glm::vec2 offset) noexcept;
      void rotate(ze::Angle angle) noexcept;

      glm::vec2 getSize() const noexcept;
      glm::vec4 getViewport() const noexcept;
      glm::vec2 getCentre() const noexcept;
      ze::Angle getRotation() const noexcept;

      View(glm::vec2 size, glm::vec2 centrePos = {}, glm::vec4 viewport = { 0.f, 0.f, 1.f, 1.f });

   private:
      mutable glm::mat4 m_view;
      mutable glm::mat4 m_projection;
      mutable bool m_viewDirty;
      mutable bool m_projDirty;

      glm::vec2 m_size;
      glm::vec4 m_viewport;

      glm::vec2 m_centre;
      ze::Angle m_rotation;
   };
}

#include "View.inl"

#endif // ZG_VIEW_HPP
