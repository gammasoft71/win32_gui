#pragma once
#include <Windows.h>

namespace win32 {
  struct message {
    HWND hwnd = nullptr;
    UINT msg = WM_NULL;
    WPARAM wparam = 0;
    LPARAM lparam = 0;
  };
}