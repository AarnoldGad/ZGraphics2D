#include "zgpch.hpp"

#include "zgraphics2D/Engine/Context.hpp"

#include "detail/Context/ContextImpl.hpp"

namespace zg
{
   void Context::Initialise()
   {
      details::ContextImpl::Initialise();
   }

   void Context::LoadAPI()
   {
      details::ContextImpl::LoadAPI();
   }

   void Context::Terminate()
   {
      details::ContextImpl::Terminate();
   }
}

