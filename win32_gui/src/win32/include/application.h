#pragma once
namespace win32 {
  /// @cond
  class form;
  /// @endcond

  class application /* static */ {
  public:
    /// @name Methods
    /// @{

    static void exit();
    static void exit(int exit_code);

    static void run();
    static void run(const win32::form& form);
    /// @}

  private:
    application() = delete;
  };
}