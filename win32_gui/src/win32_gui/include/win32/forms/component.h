#pragma once
#include "../object.h"

namespace win32 {
  namespace forms {
    class component : public object {
    public:
      /// @name Constructors

      /// @{
      component() = default;
      /// @}

      /// @cond
      component(const component&) = delete;
      component(component&&) = delete;
      /// @endcond

    protected:
      /// @name Protected Properties

      /// @{
      /// @}

    private:
    };
  }
}