#pragma once
#include "control.h"
#include "dialog_result.h"

namespace win32 {
  class application;

  class form : public control {
  public:
    virtual void activate();

    void close();

    dialog_result show_dialog(const iwin32_window& control);

  protected:
    struct create_params create_params() const noexcept override;

    SIZE default_size() const noexcept override;

    void end_dialog(dialog_result result);

    LRESULT wnd_proc(const message& message) override;

  private:
    friend class win32::application;
    void set_as_main_window();
    LRESULT wm_command(const message& message);

    struct data {
      bool main_window = false;
      bool show_dialog = false;
      dialog_result dialog_result = dialog_result::none;
    };
    std::shared_ptr<data> data_ = std::make_shared<data>();
  };
}