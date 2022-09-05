#pragma once
namespace win32 {
  /// @cond
  class form;
  /// @endcond

  class application {
  public:
    static void exit();
    static void exit(int exit_code);

    static void run();
    static void run(const win32::form& form);

  private:
    application() = delete;
  };
}