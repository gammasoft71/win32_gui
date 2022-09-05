#pragma once
#include "event_args.h"
#include <functional>

namespace win32 {
  ///  @cond
  class control;
  ///  @endcond

  using event_handler = std::function<void(control&, const event_args&)>;
}