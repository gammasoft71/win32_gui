#pragma once
#include <Windows.h>

namespace win32 {
  enum class bounds_specified {
    none = 0,
    x = 0b1,
    y = 0b10,
    location = x | y,
    width = 0b100,
    height = 0b1000,
    size = width | height,
    all = location | size,
  };

  /// @cond
  inline bounds_specified& operator +=(bounds_specified& lhs, bounds_specified rhs) { lhs = static_cast<bounds_specified>(static_cast<long long>(lhs) + static_cast<long long>(rhs)); return lhs; }
  inline bounds_specified& operator -=(bounds_specified& lhs, bounds_specified rhs) { lhs = static_cast<bounds_specified>(static_cast<long long>(lhs) - static_cast<long long>(rhs)); return lhs; }
  inline bounds_specified& operator &=(bounds_specified& lhs, bounds_specified rhs) { lhs = static_cast<bounds_specified>(static_cast<long long>(lhs) & static_cast<long long>(rhs)); return lhs; }
  inline bounds_specified& operator |=(bounds_specified& lhs, bounds_specified rhs) { lhs = static_cast<bounds_specified>(static_cast<long long>(lhs) | static_cast<long long>(rhs)); return lhs; }
  inline bounds_specified& operator ^=(bounds_specified& lhs, bounds_specified rhs) { lhs = static_cast<bounds_specified>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs)); return lhs; }
  inline bounds_specified operator +(bounds_specified lhs, bounds_specified rhs) { return static_cast<bounds_specified>(static_cast<long long>(lhs) + static_cast<long long>(rhs)); }
  inline bounds_specified operator -(bounds_specified lhs, bounds_specified rhs) { return static_cast<bounds_specified>(static_cast<long long>(lhs) - static_cast<long long>(rhs)); }
  inline bounds_specified operator ~(bounds_specified rhs) { return static_cast<bounds_specified>(~static_cast<long long>(rhs)); }
  inline bounds_specified operator &(bounds_specified lhs, bounds_specified rhs) { return static_cast<bounds_specified>(static_cast<long long>(lhs) & static_cast<long long>(rhs)); }
  inline bounds_specified operator |(bounds_specified lhs, bounds_specified rhs) { return static_cast<bounds_specified>(static_cast<long long>(lhs) | static_cast<long long>(rhs)); }
  inline bounds_specified operator ^(bounds_specified lhs, bounds_specified rhs) { return static_cast<bounds_specified>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs)); }
  /// @endcond
}