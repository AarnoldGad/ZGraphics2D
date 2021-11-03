#include "zgpch.hpp"

#include "zgraphics2D/Renderer/Transforms/FPSCamera.hpp"

namespace zg
{
   FPSCamera::FPSCamera(ze::Angle fov, float ratio, float sensitivity, glm::vec3 pos, glm::vec3 front, glm::vec3 up)
      : Camera(fov, ratio, pos, front, up),  m_sensitivity(sensitivity) {}

   void FPSCamera::setSensitivity(float sensitivity) noexcept
   {
      m_sensitivity = sensitivity;
   }

   void FPSCamera::setPitch(ze::Angle pitch) noexcept
   {
      m_pitch = pitch;
      m_pitch.clamp(ze::degrees(-89.9f), ze::degrees(89.9f));
   }

   void FPSCamera::setYaw(ze::Angle yaw) noexcept
   {
      m_yaw = yaw;
      m_yaw.normalise();
   }

   void FPSCamera::turn(glm::vec2 offset)
   {
      m_pitch += ze::degrees(offset.y * m_sensitivity);
      m_yaw -= ze::degrees(offset.x * m_sensitivity);

      m_pitch.clamp(ze::degrees(-89.9f), ze::degrees(89.9f));
      m_yaw.normalise();

      glm::vec3 front;
      front.x = glm::cos(m_pitch.asRadians()) * glm::cos(m_yaw.asRadians());
      front.y = glm::sin(m_pitch.asRadians());
      front.z = glm::cos(m_pitch.asRadians()) * glm::sin(m_yaw.asRadians());
      setFront(front);
   }
}