#pragma once
#include "key_press_event_args.h"
#include "event_handler.h"

namespace win32 {
  using key_press_event_handler = generic_event_handler<key_press_event_args&>;
}