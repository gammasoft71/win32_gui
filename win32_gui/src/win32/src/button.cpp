#include "../include/button.h"

using namespace win32;

enum class dialog_result button::dialog_result() const noexcept {
  return data_->dialog_result;
}

void button::dialog_result(enum class dialog_result value) {
  data_->dialog_result = value;
}

struct create_params button::create_params() const noexcept {
  ::create_params cp = control::create_params();
  cp.class_name = WC_BUTTON;
  cp.styles |= WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_MULTILINE | BS_CENTER | BS_VCENTER;
  return cp;
}

SIZE button::default_size() const noexcept {
  return { 75, 25 }; 
}
