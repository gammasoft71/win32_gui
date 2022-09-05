#pragma once
#include "event_args.h"
#include "message.h"
#include <Windows.h>
#include <functional>

namespace win32 {
  /// @cond
  class control;
  class form;
  /// @endcond

  class application /* static */ {
  public:
    /// @name Events
    /// @{
    static std::function<void(const event_args&)> idle;
    /// @{

    /// @name Methods
    /// @{

    static void exit();
    static void exit(int exit_code);

    static void run();
    static void run(const win32::form& form);

    /// @}

  private:
    friend class win32::control;
    application() = delete;
    static LRESULT wnd_proc(const message& message);
    static LRESULT wm_activateapp(const message& message);
    static LRESULT wm_app_ilde(const message& message);
    static LRESULT wm_quit(const message& message);
  };
}