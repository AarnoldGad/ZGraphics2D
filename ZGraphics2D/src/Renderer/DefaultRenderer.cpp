#include "zgpch.hpp"

#include "zgraphics2D/Renderer/DefaultRenderer.hpp"

namespace zg
{
   void DefaultRenderer::setLayout(VertexLayout const& layout)
   {
      m_vbo.bind(); // Need to bind vbo to change layout
      m_vao.setLayout(layout);
   }

   void DefaultRenderer::setViewProjection(ViewProjection const* viewProjection) noexcept
   {
      m_viewProjection = viewProjection;
   }

   void DefaultRenderer::submit(Renderable const& object, glm::mat4 transform)
   {
      m_objects.emplace(&object, transform);
   }

   void DefaultRenderer::render(Shader& shader)
   {
      shader.use();

      shader.setMatrix4("view", m_viewProjection->getView());
      shader.setMatrix4("projection", m_viewProjection->getProjection());

      for (auto& object : m_objects)
      {
         for (size_t i = 0; i < object.first->getTextureCount(); ++i)
         {
            glActiveTexture(GL_TEXTURE0 + i);
            object.first->getTexture(i)->bind();
            shader.setInteger("tex" + std::to_string(i), (int) i);
         }

         m_vao.bind();

         m_vbo.resize(object.first->getVertexCount()*5*sizeof(float));

         m_ebo.setData(sizeof(unsigned int) * object.first->getElementCount(), object.first->getElements());

         {
            float* buffer = m_vbo.map<float>();
            for (size_t i = 0; i < object.first->getVertexCount(); ++i)
            {
               buffer[i*5] = reinterpret_cast<glm::vec3 const*>(object.first->getVertex(i)->getLocationData(0))->x;
               buffer[i*5 + 1] = reinterpret_cast<glm::vec3 const*>(object.first->getVertex(i)->getLocationData(0))->y;
               buffer[i*5 + 2] = reinterpret_cast<glm::vec3 const*>(object.first->getVertex(i)->getLocationData(0))->z;
               buffer[i*5 + 3] = reinterpret_cast<glm::vec2 const*>(object.first->getVertex(i)->getLocationData(1))->x;
               buffer[i*5 + 4] = reinterpret_cast<glm::vec2 const*>(object.first->getVertex(i)->getLocationData(1))->y;
            }
            m_vbo.unmap();
         }

         shader.setMatrix4("model", object.second);

         glDrawElements(GL_TRIANGLES, object.first->getElementCount(), GL_UNSIGNED_INT, 0);
      }

      m_objects.clear();
   }
}
