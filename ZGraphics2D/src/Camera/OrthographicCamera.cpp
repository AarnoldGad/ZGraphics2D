#include "zgpch.hpp"

#include "zgraphics2D/Camera/OrthographicCamera.hpp"

namespace zg
{
   OrthographicCamera::OrthographicCamera(glm::vec2 size, glm::vec2 centre)
      : m_viewDirty(true), m_projDirty(true), m_size(size), m_centre(centre) {}

   glm::mat4 const& OrthographicCamera::getViewMatrix() const
   {
      if (m_viewDirty)
      {
         m_view = glm::mat4(1.f);

         m_view = glm::translate(m_view, glm::vec3(-m_centre + m_size / 2.f, 0.f));
         m_view = glm::rotate(m_view, m_rotation.asRadians(), { 0.f, 0.f, 1.f });

         m_viewDirty = false;
      }

      return m_view;
   }

   glm::mat4 const& OrthographicCamera::getProjectionMatrix() const
   {
      if (m_projDirty)
      {
         m_projection = glm::ortho(0.f, m_size.x, m_size.y, 0.f, 0.f, 100.f);

         m_projDirty = false;
      }

      return m_projection;
   }

   void OrthographicCamera::setSize(glm::vec2 size) noexcept
   {
      m_size = size;
      m_projDirty = true;
   }

   void OrthographicCamera::setCentre(glm::vec2 pos) noexcept
   {
      m_centre = pos;
      m_viewDirty = true;
   }

   void OrthographicCamera::setRotation(ze::Angle angle) noexcept
   {
      m_rotation = angle;
      m_viewDirty = true;
   }

   void OrthographicCamera::move(glm::vec2 offset) noexcept
   {
      m_centre += offset;
      m_viewDirty = true;
   }

   void OrthographicCamera::rotate(ze::Angle angle) noexcept
   {
      m_rotation += angle;
      m_viewDirty = true;
   }
}