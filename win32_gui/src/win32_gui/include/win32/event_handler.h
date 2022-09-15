#pragma once
#include "event_args.h"
#include "delegate.h"
#include "object.h"

namespace win32 {
  namespace forms {
  }

  /// @brief Represents the method that will handle an event when the event provides data.
  /// @tparam event_args_t The type of the event data generated by the event.
  /// @param sender The source of the event.
  /// @param e An object that contains the event data.
  template<typename event_args_t = const win32::event_args&>
  using generic_event_handler = win32::delegate<void(win32::object& sender, event_args_t e)>;

  /// @brief Represents the method that will handle an event that has no event data.
  /// @param sender The source of the event.
  /// @param e An object that contains no event data.
  using event_handler = generic_event_handler<>;
}