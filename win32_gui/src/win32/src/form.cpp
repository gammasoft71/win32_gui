#pragma once
#include "../include/application.h"
#include "../include/button.h"
#include "../include/form.h"

using namespace win32;

form::form() {
  set_state(state::visible, false);
  create_control();
}

void form::activate() {
  SetActiveWindow(handle());
}

control& form::client_size(SIZE value) {
  RECT rect = client_rectangle();
  RECT adjusted_rect = {0, 0, value.cx, value.cy};
  if (window_style() != WS_OVERLAPPED) AdjustWindowRectEx(&adjusted_rect, window_style(), data_->main_menu != nullptr, window_ex_style());
  bounds_specified specified = bounds_specified::none;
  if (rect.right != adjusted_rect.right) specified |= bounds_specified::width;
  if (rect.bottom != adjusted_rect.bottom) specified |= bounds_specified::height;
  if (specified == bounds_specified::none) return *this;
  on_client_size_changed(event_args::empty);
  set_bound_core(0, 0, adjusted_rect.right, adjusted_rect.bottom, specified);
  return *this;
}

void form::close() {
  if (data_->main_window) application::exit();
  else if (data_->show_dialog) end_dialog(dialog_result::cancel);
  else {
    if (is_handle_created()) CloseWindow(handle());
    visible(false);
  }
}

dialog_result form::show_dialog(const iwin32_window& control) {
  SetSysModalWindow(handle());
  if (control.handle() != nullptr) EnableWindow(control.handle(), false);
  data_->show_dialog = true;
  show();
  application::raise_enter_thread_modal();
  while (data_->show_dialog)
    application::do_events();
  application::raise_leave_thread_modal();
  data_->show_dialog = false;
  if (control.handle() != nullptr) EnableWindow(control.handle(), true);
  close();
  if (control.handle() != nullptr) SetActiveWindow(control.handle());
  return data_->dialog_result;
}

struct win32::create_params form::create_params() const noexcept {
  win32::create_params cp = control::create_params();
  cp.style |= WS_OVERLAPPEDWINDOW;
  return cp;
}

SIZE form::default_size() const noexcept {
  return { 300, 300 }; 
}

void form::end_dialog(dialog_result dialog_result) {
  data_->show_dialog = false;
  data_->dialog_result = dialog_result;
}

void form::wnd_proc(message& message) {
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

void form::wm_command(message& message) {
  if (data_->show_dialog) {
    auto control = from_handle(reinterpret_cast<HWND>(message.lparam));
    if (control.has_value() && dynamic_cast<button*>(&control.value().get())) {
      if (dynamic_cast<button*>(&control.value().get())->dialog_result() != dialog_result::none) {
        end_dialog(dynamic_cast<button*>(&control.value().get())->dialog_result());
      }
    }
  }
  control::wnd_proc(message);
}