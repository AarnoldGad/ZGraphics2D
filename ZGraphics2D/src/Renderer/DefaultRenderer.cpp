#include "zgpch.hpp"

#include "zgraphics2D/Renderer/DefaultRenderer.hpp"

namespace zg
{
   void DefaultRenderer::setLayout(VertexLayout const& layout)
   {
      m_vbo.bind(); // Need to bind vbo to change layout
      m_vao.setLayout(layout);
   }

   void DefaultRenderer::submit(Renderable const& object)
   {
      m_objects.push_back(&object);
   }

   void DefaultRenderer::render(Shader& shader)
   {
      for (Renderable const* object : m_objects)
      {
         for (size_t i = 0; i < object->getTextureCount(); ++i)
         {
            glActiveTexture(GL_TEXTURE0 + i);
            object->getTexture(i)->bind();
            shader.setInteger("tex" + std::to_string(i), (int) i);
         }

         m_vao.bind();

         m_vbo.resize(object->getVertexCount()*5*sizeof(float));

         m_ebo.setData(sizeof(unsigned int) * object->getElementCount(), object->getElements());

         {
            float* buffer = m_vbo.map<float>();
            for (size_t i = 0; i < object->getVertexCount(); ++i)
            {
               buffer[i*5] = reinterpret_cast<glm::vec3 const*>(object->getVertex(i)->getLocationData(0))->x;
               buffer[i*5 + 1] = reinterpret_cast<glm::vec3 const*>(object->getVertex(i)->getLocationData(0))->y;
               buffer[i*5 + 2] = reinterpret_cast<glm::vec3 const*>(object->getVertex(i)->getLocationData(0))->z;
               buffer[i*5 + 3] = reinterpret_cast<glm::vec2 const*>(object->getVertex(i)->getLocationData(1))->x;
               buffer[i*5 + 4] = reinterpret_cast<glm::vec2 const*>(object->getVertex(i)->getLocationData(1))->y;
            }
            m_vbo.unmap();
         }

         glDrawElements(GL_TRIANGLES, object->getElementCount(), GL_UNSIGNED_INT, 0);
      }

      m_objects.clear();
   }
}
