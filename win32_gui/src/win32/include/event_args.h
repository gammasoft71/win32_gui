#pragma once

namespace win32 {
  struct event_args {
    /// @name Properties
    
    /// @{
    static const event_args empty;
    /// @}
  };

  /// @cond
  inline const event_args event_args::empty;
  /// @endcond
}
