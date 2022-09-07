#include "../include/label.h"

using namespace win32;

win32::create_params label::create_params() const noexcept {
  win32::create_params cp = control::create_params();
  cp.class_name = WC_STATIC;
  cp.style |= WS_CHILD | WS_VISIBLE;
  return cp;
}

SIZE label::default_size() const noexcept {
  return { 100, 23 }; 
}
