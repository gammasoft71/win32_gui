#pragma once

namespace win32 {
  namespace forms {
    enum class dialog_result {
      none = 0,
      ok = 1,
      cancel = 2,
      abort = 3,
      retry = 4,
      ignore = 5,
      yes = 6,
      no = 7
    };
  }
}