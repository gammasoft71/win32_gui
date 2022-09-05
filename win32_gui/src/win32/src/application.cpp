#include "../include/application.h"
#include "../include/form.h"
#include <Windows.h>

using namespace win32;

void application::exit() {
  exit(0);
}

void application::exit(int exit_code) {
  PostQuitMessage(exit_code);
}

void application::run() {
  MSG message;
  while (GetMessage(&message, nullptr, 0, 0))
    DispatchMessage(&message);
}

void application::run(const form& form) {
  const_cast<class form&>(form).set_as_main_window();
  run();
}
