#pragma once
#include <Windows.h>

namespace win32 {
  class event_args {
  public:
    event_args() = default;
    static const event_args empty;
  };

  inline const event_args event_args::empty;
}
