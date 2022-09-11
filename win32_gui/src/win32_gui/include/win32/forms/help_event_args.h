#pragma once
#include "../event_args.h"
#include <Windows.h>

namespace win32 {
  namespace forms {
    /// @brief Provides data for the control_added and control_removed events.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    class help_event_args : public event_args {
    public:
      /// @name Constructors

      /// @{
      /// @brief Initializes a new instance of the help_event_args class.
      /// @param mouse_pos The coordinates of the mouse pointer.
      explicit help_event_args(const POINT& mouse_pos) : mouse_pos(mouse_pos) {}
      /// @}

      /// @name Properties

      /// @{
      /// @brief Gets or sets a value indicating whether the help event was handled.
      /// @remarks If you do not set this property to true the event will be passed to Windows for additional processing.
      bool handled = false;
      /// @brief Gets the screen coordinates of the mouse pointer.
      /// @remarks You can use this information to provide help based on the position of the mouse pointer.
      POINT mouse_pos;
    };
  }
}
