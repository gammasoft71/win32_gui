#pragma once
#include "../include/application.h"
#include "../include/button.h"
#include "../include/form.h"

using namespace win32;

void form::activate() {
  SetActiveWindow(handle());
}

void form::close() {
  if (data_->main_window) application::exit();
  else if (data_->show_dialog) end_dialog(dialog_result::cancel);
  else {
    CloseWindow(handle());
    visible(false);
  }
}

dialog_result form::show_dialog(const iwin32_window& control) {
  SetSysModalWindow(handle());
  EnableWindow(control.handle(), false);
  data_->show_dialog = true;
  show();
  MSG message;
  while (data_->show_dialog) {
    GetMessage(&message, nullptr, 0, 0);
    DispatchMessage(&message);
  }
  data_->show_dialog = false;
  EnableWindow(control.handle(), true);
  close();
  SetActiveWindow(control.handle());
  return data_->dialog_result;
}

struct create_params form::create_params() const noexcept {
  ::create_params cp = control::create_params();
  cp.styles |= WS_OVERLAPPEDWINDOW;
  return cp;
}

SIZE form::default_size() const noexcept {
  return { 300, 300 }; 
}

void form::end_dialog(dialog_result dialog_result) {
  data_->show_dialog = false;
  data_->dialog_result = dialog_result;
}

LRESULT form::wnd_proc(const message& message) {
  switch (message.msg) {
  case WM_CLOSE: close(); break;
  case WM_COMMAND: return wm_command(message); break;
  default: break;
  }
  return control::wnd_proc(message);
}

void form::set_as_main_window() {
  data_->main_window = true;
  show();
}

LRESULT form::wm_command(const message& message) {
  if (data_->show_dialog) {
    auto control = from_handle(reinterpret_cast<HWND>(message.lparam));
    if (control.has_value() && dynamic_cast<button*>(&control.value().get())) {
      if (dynamic_cast<button*>(&control.value().get())->dialog_result() != dialog_result::none) {
        end_dialog(dynamic_cast<button*>(&control.value().get())->dialog_result());
      }
    }
  }
  return control::wnd_proc(message);
}