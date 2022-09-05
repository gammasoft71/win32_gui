#pragma once
#include "../include/debug.h"
#include <Windows.h>

using namespace win32;

void debug::__write__(const std::wstring& message) {
  OutputDebugString(message.c_str());
}