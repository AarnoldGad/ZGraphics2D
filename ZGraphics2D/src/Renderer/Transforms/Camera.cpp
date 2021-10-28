#include "zgpch.hpp"

#include "zgraphics2D/Renderer/Transforms/Camera.hpp"

namespace zg
{
   Camera::Camera(ze::Angle fov, float ratio, glm::vec3 pos, glm::vec3 front, glm::vec3 up)
      : m_view(), m_projection(), m_viewDirty(true), m_projectionDirty(true),
              m_pos(pos), m_front(front), m_up(up), m_fov(fov), m_ratio(ratio)
   {
   
   }

   glm::mat4 const& Camera::getView() const
   {
      if (m_viewDirty)
      {
         m_view = glm::lookAt(m_pos, m_pos + m_front, m_up);

         m_viewDirty = false;
      }

      return m_view;
   }

   glm::mat4 const& Camera::getProjection() const
   {
      if (m_projectionDirty)
      {
         m_projection = glm::perspective(m_fov.asRadians(), m_ratio, 0.1f, 100.f);

         m_projectionDirty = false;
      }

      return m_projection;
   }

   void Camera::setFront(glm::vec3 front) noexcept
   {
      m_front = front;
      m_viewDirty = true;
   }

   void Camera::setUp(glm::vec3 up) noexcept
   {
      m_up = up;
      m_viewDirty = true;
   }

   void Camera::setFieldOfView(ze::Angle fov) noexcept
   {
      m_fov = fov;
      m_projectionDirty = true;
   }

   void Camera::setAspectRatio(float ratio) noexcept
   {
      m_ratio = ratio;
      m_projectionDirty = true;
   }

   void Camera::setPosition(glm::vec3 pos) noexcept
   {
      m_pos = pos;
      m_viewDirty = true;
   }

   void Camera::move(glm::vec3 offset) noexcept
   {
      m_pos += offset;
      m_viewDirty = true;
   }
}
