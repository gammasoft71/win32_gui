#pragma once
#include "key_event_args.h"
#include "../event_handler.h"

namespace win32 {
  namespace forms {
    using key_event_handler = generic_event_handler<key_event_args&>;
  }
}