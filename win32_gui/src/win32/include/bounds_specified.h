#pragma once
#include <Windows.h>

namespace win32 {
  enum class bounds_specified {
    none = 0,
    x = 0b1,
    y = 0b10,
    location = 0b11,
    width = 0b100,
    height = 0b1000,
    size = 0b1100,
    all = 0b1111,
  };
}