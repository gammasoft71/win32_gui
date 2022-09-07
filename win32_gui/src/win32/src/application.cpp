#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include "../include/application.h"
#include "../include/dark_mode.h"
#include "../include/debug.h"
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

bool application::dark_mode_enabled() {
  return dark_mode_enabled_.value_or(is_system_dark_mode_enabled());
}

bool application::light_mode_enabled() {
  return !dark_mode_enabled();
}

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

void application::enable_dark_mode() {
  dark_mode_enabled_ = true;
}

void application::enable_light_mode() {
  dark_mode_enabled_ = false;
}

bool application::is_system_dark_mode_enabled() {
  static optional<bool> system_dark_mode_enabled;
  if (!system_dark_mode_enabled.has_value()) {
    HKEY key;
    if (RegOpenKeyEx(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", 0, KEY_READ, &key) == ERROR_SUCCESS) {
      DWORD size_value(sizeof(DWORD));
      DWORD value = 1;
      RegQueryValueEx(key, L"AppsUseLightTheme", 0, nullptr, reinterpret_cast<LPBYTE>(&value), &size_value);
      system_dark_mode_enabled = value == 0;
    }
  }
  return system_dark_mode_enabled.value_or(false);
}

void application::set_dark_mode() {
  static bool initialized = false;
  if (!initialized) win32::dark_mode::init_dark_mode(dark_mode_enabled());
  initialized = true;
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
