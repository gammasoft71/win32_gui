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

    static std::function<void(const event_args&)> application_exit;
    static std::function<void(const event_args&)> enter_thread_modal;
    static std::function<void(const event_args&)> idle;
    static std::function<void(const event_args&)> leave_thread_modal;
    static std::function<void(const event_args&)> thread_exit;
    /// @{

    /// @name Methods
    /// @{
    static void do_events();

    static void exit();
    static void exit(int exit_code);

    static void run();
    static void run(const win32::form& form);

    /// @}

  private:
    friend class win32::control;
    friend class win32::form;
    application() = delete;
    static bool do_events_();
    static void raise_enter_thread_modal();
    static void raise_leave_thread_modal();
    static void wnd_proc(message& message);
    static void wm_activateapp(message& message);
    static void wm_app_ilde(message& message);
    static void wm_quit(message& message);
  };
}