#pragma once
#include <Windows.h>

namespace win32 {
  /// @brief Specifies the bounds of the control to use when defining a control's size and position. This enumeration has a flags attribute that allows a bitwise combination of its member values.
  /// @remarks Use the members of this enumeration when calling the set_bounds_core and set_bounds methods of the control class.
  enum class bounds_specified {
    /// @brief No border.s
    none = 0,
    /// @brief Specifies that the left edge of the control is defined.
    x = 0b1,
    /// @brief Specifies that the top edge of the control is defined.
    y = 0b10,
    /// @brief Specifies that both the x and y coordinates of the control are defined.
    location = x | y,
    /// @brief Specifies that the width of the control is defined.
    width = 0b100,
    /// @brief Specifies that the height of the control is defined.
    height = 0b1000,
    /// @brief Specifies that both the width and height property values of the control are defined.
    size = width | height,
    /// @brief Specifies that both the location and size property values are defined.
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