#pragma once
#include <Windows.h>

namespace win32 {
  class dark_mode /* static */ {
  public:
    static bool allow_dark_mode_for_window(HWND handle);
    static void init_dark_mode(int enable_dark_mode);
    static void refresh_title_bar_theme_color(HWND handle);

  private:
    dark_mode() = delete;
  };
}