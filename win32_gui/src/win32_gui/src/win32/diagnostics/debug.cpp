#pragma once
#include "../../../include/win32/diagnostics/debug.h"
#include <Windows.h>

using namespace win32;
using namespace win32::diagnostics;

void debug::__write__(const std::wstring& message) {
  OutputDebugString(message.c_str());
}