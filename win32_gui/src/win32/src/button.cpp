#include "../include/button.h"
#include "../include/window_messages.h"

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

void button::wnd_proc(message& message) {
  switch (message.msg) {
  case WM_REFLECT + WM_COMMAND: wm_command_control(message); break;
  default: control::wnd_proc(message); break;
  }
}

void button::wm_command_control(win32::message& message) {
  control::wnd_proc(message);
  on_click(event_args::empty);
}
