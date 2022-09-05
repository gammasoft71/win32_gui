#pragma once
#include "control.h"
#include "dialog_result.h"

namespace win32 {
  class label : public control {
  public:

  protected:
    struct create_params create_params() const noexcept override;

    SIZE default_size() const noexcept override;

  private:

    struct data {
    };
    std::shared_ptr<data> data_ = std::make_shared<data>();
  };
}