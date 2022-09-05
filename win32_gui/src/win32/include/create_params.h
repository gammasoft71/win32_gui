#pragma once
#include <Windows.h>

namespace win32 {
  struct create_params {
    LPCWSTR class_name = WC_DIALOG;
    DWORD ex_styles = 0;
    int height = CW_USEDEFAULT;
    HWND parent = nullptr;
    DWORD styles = WS_OVERLAPPED;
    LPCWSTR text = L"";
    int width = CW_USEDEFAULT;
    int x = CW_USEDEFAULT;
    int y = CW_USEDEFAULT;
  };
}