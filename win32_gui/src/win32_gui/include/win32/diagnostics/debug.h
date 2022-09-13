#pragma once
#include "../string.h"
#define TRACE /// @todo : Remove define...

namespace win32 {
  namespace diagnostics {
    /// @brief Provides a set of methods and properties that help you debug the execution of your code. This class cannot be inherited.
    /// @remarks You can use the properties and methods in the xtd::diagnostics::debug class to instrument release builds. Instrumentation allows you to monitor the health of your application running in real-life settings. Tracing helps you isolate problems and fix them without disturbing a running system.
    /// @remarks This class provides methods to display an assert dialog box, and to emit an assertion that will always fail. This class provides write methods in the following variations: xtd::diagnostics::debug::write, xtd::diagnostics::debug::write_line, xtd::diagnostics::debug::write_if, and xtd::diagnostics::debug::write_line_if.
    /// @remarks The xtd::diagnostics::boolean_switch and xtd::diagnostics::trace_switch classes provide means to dynamically control the tracing output. You can modify the values of these switches without recompiling your application. For information on using the configuration file to set a switch, see the xtd::diagnostics::switch class and the xtd::diagnostics::trace_switches topic.
    /// @remarks You can customize the tracing output's target by adding xtd::diagnostics::trace_listener instances to or removing instances from the xtd::diagnostics::debug::listeners collection. The xtd::diagnostics::debug::listeners collection is shared by both the xtd::diagnostics::debug and the xtd::diagnostics::trace classes; adding a trace listener to either class adds the listener to both. By default, trace output is emitted using the xtd::diagnostics::default_trace_listener class.
    /// @note Adding a trace listener to the xtd::diagnostics::debug::listeners collection can cause an exception to be thrown while tracing, if a resource used by the trace listener is not available. The conditions and the exception thrown depend on the trace listener and cannot be enumerated in this topic. It may be useful to place calls to the debug methods in try/catch blocks to detect and handle any exceptions from trace listeners.
    /// @remarks You can modify the level of indentation using the xtd::diagnostics::debug::indent method or the xtd::diagnostics::debug::indent_level property. To modify the indent spacing, use the xtd::diagnostics::debug::indent_size property. You can specify whether to automatically flush the output buffer after each write by setting the xtd::diagnostics::debug::auto_flush property to true.
    /// @remarks The debug class provides properties to get or set the level of indent, the xtd::diagnostics::debug::indent_size, and whether to xtd::diagnostics::debug::auto_flush after each write.
    /// @remarks You must enable debug mode to use a trace listener. The syntax is compiler specific. If you use other than cmake to manage your build, refer to the documentation of your build manager.
    ///  * To enable debug mode with cmake, add the add_definitions(-DDEBUG) command line in the CMakeLists.txt of your project, or you can add #define DEBUG to the top of your file.
    /// @remarks To activate your code if DEBUG is defined, you must enclose calls to the methods of Debug in an #if defined(DEBUG) ... #endif block, and add the /DDEBUG option to the compiler command line or add #define DEBUG to the file.
    class debug {
    public:
      /// @name Methods

      /// @{
      /// @brief Writes a message to the trace listeners in the listeners collection.
      /// @param message A message to write.
      /// @remarks By default, the output is written to an instance of default_trace_listener.
      /// @remarks This method calls the write method of the trace listener.
      static void write(const std::wstring& message) {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        __write__(message);
#endif
      }

      /// @brief Writes a message followed by a line terminator to the trace listeners in the listeners collection.
      /// @param message A message to write.
      /// @remarks By default, the output is written to an instance of default_trace_listener.
      /// @remarks This method calls the write method of the trace listener.
      static void write_line(const std::wstring& message) {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        __write__(message);
        __write__(L"\n");
#endif
      }
      /// @}

    private:
      static void __write__(const std::wstring& message);
      debug() = delete;
    };
  }
}