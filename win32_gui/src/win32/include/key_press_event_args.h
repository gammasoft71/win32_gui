#pragma once
#include "event_args.h"
#include <Windows.h>

namespace win32 {
  class key_press_event_args : public event_args {
  public:
    /// @{
    key_press_event_args(wchar_t key) : key_char(key) {}
    /// @}

    wchar_t key_char = 0;
    bool handled = false;
  };
}
