#pragma once
#include "mouse_event_args.h"
#include "event_handler.h"

namespace win32 {
  using mouse_event_handler = generic_event_handler<const mouse_event_args&>;
}