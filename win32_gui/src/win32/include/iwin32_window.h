#pragma once
#include <Windows.h>

namespace win32 {
  class iwin32_window {
  public:
    virtual HWND handle() const = 0;
  };
}