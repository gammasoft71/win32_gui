#pragma once
#include <Windows.h>

namespace win32 {
  class iwin32_window {
  public:
    // @cond
    virtual ~iwin32_window() = default;
    // @endcond

    /// @name Properties
    /// @{

    virtual HWND handle() const = 0;
    /// @}
  };
}