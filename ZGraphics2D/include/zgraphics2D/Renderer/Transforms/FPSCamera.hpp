/**
 * FPSCamera.hpp
 * 3 Nov 2021
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
#ifndef ZG_FPSCAMERA_HPP
#define ZG_FPSCAMERA_HPP

#include "zgraphics2D/defines.hpp"

#include "zgraphics2D/Renderer/Transforms/Camera.hpp"

namespace zg
{
   class ZG_API FPSCamera : public Camera
   {
   public:
      float getSensitivity() const noexcept;
      void setSensitivity(float sensitivity) noexcept;

      ze::Angle getPitch() const noexcept;
      void setPitch(ze::Angle pitch) noexcept;

      ze::Angle getYaw() const noexcept;
      void setYaw(ze::Angle yaw) noexcept;

      void turn(glm::vec2 offset);

      FPSCamera(ze::Angle fov, float ratio, float sensitivity = 1.f, glm::vec3 pos = {}, glm::vec3 front = { 0.f, 0.f, -1.f }, glm::vec3 up = { 0.f, 1.f, 0.f });

   private:
      float m_sensitivity;
      ze::Angle m_pitch;
      ze::Angle m_yaw;
   };
}

#include "FPSCamera.inl"

#endif // ZG_FPSCAMERA_HPP