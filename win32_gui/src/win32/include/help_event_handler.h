#pragma once
#include "help_event_args.h"
#include "event_handler.h"

namespace win32 {
  using help_event_handler = generic_event_handler<help_event_args&>;
}