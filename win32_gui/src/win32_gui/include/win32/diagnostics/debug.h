#pragma once
#include "../string.h"
#define TRACE /// @todo : Remove define...

namespace win32 {
  namespace diagnostics {
    class debug {
    public:
      /// @name Methods

      /// @{
      static void write(const std::wstring& message) {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        __write__(message);
#endif
      }
      static void write_line(const std::wstring& message) {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        __write__(message);
        __write__(L"\n");
#endif
      }
      /// @}

    private:
      static void __write__(const std::wstring& message);
      debug() = delete;
    };
  }
}