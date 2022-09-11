#pragma once
#include "control.h"
#include "dialog_result.h"

namespace win32 {
  namespace forms {
    /// @cond
    class application;
    /// @endcond

    class form : public control {
    public:
      /// @name Constructors

      /// @{
      form();
      /// @}

      /// @name Properties

      /// @{
      virtual void activate();
      using control::client_size;
      control& client_size(SIZE value) override;

      /// @}

      /// @name Methods

      /// @{
      void close();

      win32::forms::dialog_result show_dialog(const win32::forms::iwin32_window& control);
      /// @}

    protected:
      /// @name Protected Properties

      /// @{
      win32::forms::create_params create_params() const noexcept override;

      SIZE default_size() const noexcept override;
      /// @}

      /// @name Protected Methods

      /// @{
      void end_dialog(win32::forms::dialog_result result);

      void wnd_proc(win32::forms::message& message) override;
      /// @}

    private:
      friend class win32::forms::application;
      void set_as_main_window();
      void wm_command(win32::forms::message& message);

      struct data {
        HWND main_menu = nullptr;
        bool main_window = false;
        bool show_dialog = false;
        win32::forms::dialog_result dialog_result = win32::forms::dialog_result::none;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}