#include "../include/button.h"
#include "../include/window_messages.h"

using namespace win32;

button::button() {
  set_style(control_styles::standard_click | control_styles::standard_double_click, false);
}

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
