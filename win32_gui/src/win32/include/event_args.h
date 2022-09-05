#pragma once

namespace win32 {
  class event_args {
  public:
    /// @name Constructors
    /// @{

    event_args() = default;
    /// @}

    /// @name Properties
    /// @{

    static const event_args empty;
    /// @}
  };

  /// @cond
  inline const event_args event_args::empty;
  /// @endcond
}
