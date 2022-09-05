#pragma once
#include "control.h"
#include "dialog_result.h"

namespace win32 {
  class button : public control {
  public:
    /// @name Constructors
    /// @{

    button() = default;
    /// @}

    /// @name Properties
    /// @{

    virtual win32::dialog_result dialog_result() const noexcept;
    virtual void dialog_result(win32::dialog_result value);
    /// @}

  protected:
    /// @name Protected Methods
    /// @{

    win32::create_params create_params() const noexcept override;

    SIZE default_size() const noexcept override;
    /// @}

  private:
    struct data {
      win32::dialog_result dialog_result = win32::dialog_result::none;
    };
    std::shared_ptr<data> data_ = std::make_shared<data>();
  };
}