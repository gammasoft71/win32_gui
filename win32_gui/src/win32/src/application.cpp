#include "../include/application.h"
#include "../include/debug.h"
#include "../include/form.h"
#include "../include/window_messages.h"
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;
using namespace std::chrono_literals;
using namespace win32;

std::function<void(const event_args&)> application::idle;

void application::exit() {
  exit(0);
}

void application::exit(int exit_code) {
  PostQuitMessage(exit_code);
}

void application::run() {
  static auto last_idle_time = high_resolution_clock::now();;
  MSG message;
  while (true) {
    if (PeekMessage(&message, nullptr, 0, 0, PM_NOREMOVE) != 0) {
      if (GetMessage(&message, NULL, 0, 0) == 0) break;
      TranslateMessage(&message);
      DispatchMessage(&message);
    } else {
      if (high_resolution_clock::now() - last_idle_time < 100ms) this_thread::sleep_for(2ms);
      else {
        wnd_proc({ 0, WM_PROCESSIDLE, 0, 0 });
        last_idle_time = high_resolution_clock::now();
      }
    }
  }
  wnd_proc({ 0, WM_QUIT, 0, 0 });
}

void application::run(const form& form) {
  const_cast<class form&>(form).set_as_main_window();
  run();
}

LRESULT application::wnd_proc(const message& message) {
  switch (message.msg) {
  case WM_ACTIVATEAPP: return wm_activateapp(message); break;
  case WM_PROCESSIDLE: return wm_processidle(message); break;
  case WM_QUIT: return wm_quit(message); break;
  default: return 0; break;
  }
  return 0;
}

LRESULT application::wm_activateapp(const message& message) {
  debug::write_line(string_format(L"Activate application %s", message.wparam ? L"true" : L"false"));
  return 0;
}
LRESULT application::wm_processidle(const message& message) {
  static auto cpt = 0;
  debug::write_line(string_format(L"Idle %d... ", ++cpt));
  if (idle) idle(event_args::empty);
  return 0;
}

LRESULT application::wm_quit(const message& message) {
  debug::write_line(L"Quit application");
  return 0;
}
