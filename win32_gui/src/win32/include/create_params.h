#pragma once
#include <Windows.h>

namespace win32 {
  struct create_params {
    LPCWSTR class_name = WC_DIALOG;
    DWORD ex_style = 0;
    int height = CW_USEDEFAULT;
    HWND parent = nullptr;
    DWORD style = WS_OVERLAPPED;
    LPCWSTR text = L"";
    int width = CW_USEDEFAULT;
    int x = CW_USEDEFAULT;
    int y = CW_USEDEFAULT;
  };
}