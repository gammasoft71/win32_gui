#include "../include/button.h"

using namespace win32;

win32::dialog_result button::dialog_result() const noexcept {
  return data_->dialog_result;
}

button& button::dialog_result(win32::dialog_result value) {
  data_->dialog_result = value;
  return *this;
}

win32::create_params button::create_params() const noexcept {
  win32::create_params cp = control::create_params();
  cp.class_name = WC_BUTTON;
  cp.style |= WS_CHILD | BS_PUSHBUTTON | BS_MULTILINE | BS_CENTER | BS_VCENTER;
  return cp;
}

SIZE button::default_size() const noexcept {
  return { 75, 25 }; 
}
