#pragma once
#include "../include/debug.h"

using namespace win32;

void debug::__write__(LPCWCHAR message) {
  OutputDebugString(message);
}