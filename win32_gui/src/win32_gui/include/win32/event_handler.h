#pragma once
#include "event_args.h"
#include "delegate.h"

namespace win32 {
  namespace forms {
    ///  @cond
    class control;
    ///  @endcond
  }

  template<typename event_args_t = const win32::event_args&>
  using generic_event_handler = win32::delegate<void(win32::forms::control& sender, event_args_t e)>;

  using event_handler = generic_event_handler<>;
}