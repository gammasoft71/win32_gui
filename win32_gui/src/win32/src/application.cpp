#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include "../include/application.h"
#include "../include/form.h"
#include "../include/window_messages.h"
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;
using namespace std::chrono_literals;
using namespace win32;

event<application, delegate<void(const event_args&)>> application::application_exit;
event<application, delegate<void(const event_args&)>> application::enter_thread_modal;
event<application, delegate<void(const event_args&)>> application::idle;
event<application, delegate<void(const event_args&)>> application::leave_thread_modal;
event<application, delegate<void(const event_args&)>> application::thread_exit;

void application::do_events() {
  do_events_();
}

void application::exit() {
  exit(0);
}

void application::exit(int exit_code) {
  PostQuitMessage(exit_code);
}

void application::run() {
  while (do_events_());
  win32::message message { 0, WM_QUIT, 0, 0 };
  wnd_proc(message);
}

void application::run(const form& main_form) {
  const_cast<class form&>(main_form).set_as_main_window();
  run();
}

bool application::do_events_() {
  MSG message;
  if (PeekMessage(&message, nullptr, 0, 0, PM_NOREMOVE) != 0) {
    if (GetMessage(&message, NULL, 0, 0) == 0) return false;
    TranslateMessage(&message);
    DispatchMessage(&message);
  }
  else {
    static auto last_idle_time = high_resolution_clock::now();;
    if (high_resolution_clock::now() - last_idle_time < 100ms) this_thread::sleep_for(2ms);
    else {
      win32::message message{ 0, WM_APPIDLE, 0, 0 };
      wnd_proc(message);
      last_idle_time = high_resolution_clock::now();
    }
  }
  return true;
}

void application::raise_enter_thread_modal() {
  application::enter_thread_modal(event_args::empty);
}

void application::raise_leave_thread_modal() {
  application::leave_thread_modal(event_args::empty);
}

void application::wnd_proc(message& message) {
  switch (message.msg) {
  case WM_ACTIVATEAPP: wm_activateapp(message); break;
  case WM_APPIDLE: wm_app_ilde(message); break;
  case WM_QUIT: wm_quit(message); break;
  default: break;
  }
}

void application::wm_activateapp(message& message) {
}

void application::wm_app_ilde(message& message) {
  idle(event_args::empty);
}

void application::wm_quit(message& message) {
  thread_exit(event_args::empty);
  application_exit(event_args::empty);
}
