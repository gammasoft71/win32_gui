#pragma once
#include "event_args.h"
#include "message.h"
#include "mouse_buttons.h"

namespace win32 {
  /// @cond
  class control;
  /// @endcond

  /// @brief Provides data for the xtd::forms::control::mouse_up, xtd::forms::control::mouse_down, and xtd::forms::control::mouse_move events.
  struct mouse_event_args : public event_args {
    /// @name Constructors

    /// @{
    /// @brief Initializes a new instance of the MouseEventArgs class.
    mouse_event_args() = default;
    /// @brief Initializes a new instance of the MouseEventArgs class.
    /// @param button One of the win32::mouse_buttons values that indicate which mouse button was pressed.
    /// @param clicks The number of times a mouse button was pressed.
    /// @param x The x-coordinate of a mouse click, in pixels.
    /// @param y The y-coordinate of a mouse click, in pixels.
    /// @param delta A signed count of the number of detents the wheel has rotated.
    mouse_event_args(mouse_buttons button, INT32 clicks, INT32 x, INT32 y, INT32 delta) : button(button), x(x), y(y), clicks(clicks), delta(delta) {}
    /// @brief Initializes a new instance of the MouseEventArgs class.
    /// @param button One of the win32::mouse_buttons values that indicate which mouse button was pressed.
    /// @param clicks The number of times a mouse button was pressed.
    /// @param location The location of a mouse click, in pixels.
    /// @param delta A signed count of the number of detents the wheel has rotated.
    mouse_event_args(mouse_buttons button, INT32 clicks, const POINT& location, INT32 delta) : button(button), x(location.x), y(location.y), clicks(clicks), delta(delta) {}
    /// @}

/// @cond
    mouse_event_args(const mouse_event_args& mouse_event_args) = default;
    mouse_event_args& operator=(const mouse_event_args& mouse_event_args) = default;
    /// @endcond

    /// @name Properties

    /// @{
    /// @brief Gets the location of the mouse during the generating mouse event.
       /// @return A POINT that contains the x and y mouse coordinates, in pixels, relative to the upper-left corner of the form.
    POINT location()  { return POINT{x, y}; }
    /// @}

    /// @name Members

    /// @{
    /// @brief Gets which mouse button was pressed.
    mouse_buttons button = mouse_buttons::none;
    /// @brief Gets the number of times the mouse button was pressed and released.
    INT32 clicks = 0;
    /// @brief Gets a signed count of the number of detents the mouse wheel has rotated, multiplied by the WHEEL_DELTA constant. A detent is one notch of the mouse wheel.
    INT32 delta = 0;
    /// @brief Gets the x-coordinate of the mouse during the generating mouse event.
    /// @return The x-coordinate of the mouse, in pixels.
    LONG x = 0;

    /// @brief Gets the y-coordinate of the mouse during the generating mouse event.
    /// @return The y-coordinate of the mouse, in pixels.
    LONG y = 0;
    /// @}
  };
}
