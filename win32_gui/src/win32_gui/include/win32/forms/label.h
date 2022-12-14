#pragma once
#include "control.h"
#include "dialog_result.h"

namespace win32 {
  namespace forms {
    class label : public control {
    public:
      /// @name Constructors

      /// @{
      label() = default;
      /// @}

    protected:
      /// @name Protected Properties

      /// @{
      win32::forms::create_params create_params() const noexcept override;

      SIZE default_size() const noexcept override;
      /// @}

    private:
      struct data {
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}