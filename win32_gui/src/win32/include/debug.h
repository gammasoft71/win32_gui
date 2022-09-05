#pragma once
#include <Windows.h>

namespace win32 {
  class debug {
  public:
    static void write(LPCWCHAR message) {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
      __write__(message);
#endif
    }
    static void write_line(LPCWCHAR message) {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
      __write__(message);
      __write__(L"\n");
#endif
    }


  private:
    static void __write__(LPCWCHAR message);
    debug() = delete;
  };
}