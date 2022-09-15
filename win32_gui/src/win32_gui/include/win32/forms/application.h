#pragma once
#include "../event.h"
#include "../event_handler.h"
#include "message.h"
#include <Windows.h>
#include <functional>
#include <optional>

namespace win32 {
  namespace forms {
    /// @cond
    class control;
    class form;
    /// @endcond

    /// @brief Provides static methods and properties to manage an application, such as methods to start and stop an application, to process Windows messages, and methods to get information about an application. This class cannot be inherited.
    /// @remarks The application class has methods to start and stop applications and threads, and to process Windows messages, as follows:
    /// * run() starts an application message loop on the current thread and, optionally, makes a form visible.
    /// * exit() or exit_thread() stops a message loop.
    /// * do_events() processes messages while your program is in a loop.
    /// * add_message_filter() adds a message filter to the application message pump to monitor Windows messages.
    /// @remarks You cannot create an instance of this class.
    class application /* static */ {
    public:
      /// @name Events

      /// @{
      /// @brief Return true if dark mode is enabled for the application; otherwise return false.
      /// @return True is dark mode enabled; otherwise false.
      static bool dark_mode_enabled();
      /// @brief Return true if dark mode is enabled for the application; otherwise return false.
      /// @return True is light mode enabled; otherwise false.
      static bool light_mode_enabled();
      /// @}

      /// @name Events

      /// @{
      /// @brief Occurs when the application is about to shut down.
      /// @remarks You must attach the event handlers to the application_exit event to perform unhandled, required tasks before the application stops running. You can close files opened by this application, or dispose of objects that garbage collection did not reclaim.
      static event<application, delegate<void(const event_args&)>> application_exit;
      /// @brief Occurs when the application is about to enter a modal state.
      static event<application, delegate<void(const event_args&)>> enter_thread_modal;
      /// @brief Occurs when the application finishes processing and is about to enter the idle state.
      /// @remarks If you have tasks that you must perform before the thread becomes idle, attach them to this event.
      static event<application, delegate<void(const event_args&)>> idle;
      /// @brief Occurs when the application is about to leave a modal state.
      static event<application, delegate<void(const event_args&)>> leave_thread_modal;
      /// @brief Occurs when a thread is about to shut down. When the main thread for an application is about to be shut down, this event is raised first, followed by an application_exit event.
      /// @remarks You must attach the event handlers to the thread_exit event to perform any unhandled, required tasks before the thread stops running. Close files opened by this thread, or dispose of objects that the garbage collector did not reclaim.
      static event<application, delegate<void(const event_args&)>> thread_exit;
      /// @}

      /// @name Methods

      /// @{
      /// @brief Processes all Windows messages currently in the message queue.
      /// @remarks When you run a Windows form, it creates the new form, which then waits for events to handle. Each time the form handles an event, it processes all the code associated with that event. All other events wait in the queue. While your code handles the event, your application does not respond. For example, the window does not repaint if another window is dragged on top.
      /// @remarks If you call do_events in your code, your application can handle the other events. For example, if you have a form that adds data to a list_box and add do_events to your code, your form repaints when another window is dragged over it. If you remove do_events from your code, your form will not repaint until the click event handler of the button is finished executing.
      /// @remarks Typically, you use this method in a loop to process messages.
      /// @warning Calling this method causes the current thread to be suspended while all waiting window messages are processed. If a message causes an event to be triggered, then other areas of your application code may execute. This can cause your application to exhibit unexpected behaviors that are difficult to debug. If you perform operations or computations that take a long time, it is often preferable to perform those operations on a new thread.
      static void do_events();

      /// @brief Enables dark mode for the application.
      /// @remarks By default, the dark mode is enabled automatically if the system is in dark mode.
      /// @remarks xtd::forms::application::enable_dark_mode sets the application in dark mode even if your system is in light mode.
      static void enable_dark_mode();

      /// @brief Enables light mode for the application.
      /// @remarks By default, the light mode is enabled automatically if the system is in light mode.
      /// @remarks xtd::forms::application::enable_light_mode sets the application in light mode even if your system is in dark mode.
      static void enable_light_mode();

      /// @brief Informs all message pumps that they must terminate, and then closes all application windows after the messages have been processed.
      /// @remarks The exit method stops all running message loops on all threads and closes all windows of the application. This method does not necessarily force the application to exit. The exit method is typically called from within a message loop, and forces Run to return. To exit a message loop for the current thread only, call exit_thread.
      /// @remarks Exit raises the following events and performs the associated conditional actions:
      /// * A form_closing event is raised for every form represented by the open_forms property. This event can be canceled by setting the cancel property of their form_closing_event_args parameter to true.
      /// * If one of more of the handlers cancels the event, then exit returns without further action. Otherwise, a form_closed event is raised for every open form, then all running message loops and forms are closed.
      static void exit();
      /// @brief Informs all message pumps that they must terminate, and then closes all application windows after the messages have been processed.
      /// @param exit_code The specofied exit code. 
      /// @remarks The exit method stops all running message loops on all threads and closes all windows of the application. This method does not necessarily force the application to exit. The exit method is typically called from within a message loop, and forces Run to return. To exit a message loop for the current thread only, call exit_thread.
      /// @remarks Exit raises the following events and performs the associated conditional actions:
      /// * A form_closing event is raised for every form represented by the open_forms property. This event can be canceled by setting the cancel property of their form_closing_event_args parameter to true.
      /// * If one of more of the handlers cancels the event, then exit returns without further action. Otherwise, a form_closed event is raised for every open form, then all running message loops and forms are closed.
      static void exit(int exit_code);

      /// @brief Begins running a standard application message loop on the current thread, without a form.
      /// @remarks In a Win32-based or Windows Forms application, a message loop is a routine in code that processes user events, such as mouse clicks and keyboard strokes. Every running Windows-based application requires an active message loop, called the main message loop. When the main message loop is closed, the application exits. In Windows Forms, this loop is closed when the exit method is called, or when the exit_thread method is called on the thread that is running the main message loop.
      /// @remarks Most Windows Forms developers will not need to use this version of the method. You should use the run(const form&) overload to start an application with a main form, so that the application terminates when the main form is closed. For all other situations, use the run(application_context&) overload, which supports supplying an application_context object for better control over the lifetime of the application.
      static void run();
      /// @brief Begins running a standard application message loop on the current thread, and makes the specified form visible.
      /// @param main_form A form that represents the form to make visible.
      /// @remarks Typically, the main function of an application calls this method and passes to it the main window of the application.
      /// @remarks This method adds an event handler to the main_form parameter for the closed event. The event handler calls exit_thread to clean up the application.
      static void run(const win32::forms::form& main_form);
      /// @}

    private:
      friend class win32::forms::control;
      friend class win32::forms::form;
      application() = delete;
      static bool do_events_();
      static bool is_system_dark_mode_enabled();
      static void set_dark_mode();
      static void raise_enter_thread_modal();
      static void raise_leave_thread_modal();
      static void wnd_proc(message& message);
      static void wm_activateapp(message& message);
      static void wm_app_ilde(message& message);
      static void wm_quit(message& message);

      inline static std::optional<bool> dark_mode_enabled_;
    };
  }
}