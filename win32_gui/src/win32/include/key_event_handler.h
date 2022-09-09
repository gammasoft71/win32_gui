#pragma once
#include "key_event_args.h"
#include "event_handler.h"

namespace win32 {
  using key_event_handler = generic_event_handler<key_event_args&>;
}