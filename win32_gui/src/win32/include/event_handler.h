#pragma once
#include "event_args.h"
#include "delegate.h"

namespace win32 {
  ///  @cond
  class control;
  ///  @endcond

  template<typename event_args_t = const win32::event_args&>
  using generic_event_handler = win32::delegate<void(win32::control& sender, event_args_t e)>;

  using event_handler = generic_event_handler<>;
}