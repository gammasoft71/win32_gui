#pragma once
#include "control.h"
#include "dialog_result.h"

namespace win32 {
  /// @brief Represents a Windows button control.
  /// @remarks A button can be clicked by using the mouse, ENTER key, or SPACEBAR if the button has focus.
  /// @remarks Set the accept_button or cancel_button property of a form to allow users to click a button by pressing the ENTER or ESC keys even if the button does not have focus. This gives the form the behavior of a dialog box.
  /// @remarks When you display a form using the show_dialog method, you can use the dialog_result property of a button to specify the return value of show_dialog.
  /// @remarks You can change the button's appearance. For example, to make it appear flat for a Web look, set the flat_style property to flat_style::flat. The flat_style property can also be set to flat_style::popup, which appears flat until the mouse pointer passes over the button; then the button takes on the standard Windows button appearance.
  /// @note If the control that has focus accepts and processes the ENTER key press, the button does not process it. For example, if a multiline text_box or another button has focus, that control processes the ENTER key press instead of the accept button.
  class button : public control {
  public:
    /// @name Constructors

    /// @{
    /// @brief Initializes a new instance of the button class.
    /// @remarks By default the button displays no caption. To specify the caption text, set the text property.
    button() = default;
    /// @}

    /// @name Properties
    
    /// @{
    /// @brief Gets the value returned to the parent form when the button is clicked.
    /// @return One of the dialog_result values.
    /// @remarks When a form is shown as a dialog box using the show_dialog method and one of its buttons is clicked, the button's dialog_result value is assigned to the form's dialog_result property.
    virtual win32::dialog_result dialog_result() const noexcept;
    /// @brief Sets the value returned to the parent form when the button is clicked.
    /// @param value One of the dialog_result values.
    /// @remarks When a form is shown as a dialog box using the show_dialog method and one of its buttons is clicked, the button's dialog_result value is assigned to the form's dialog_result property.
    virtual button& dialog_result(win32::dialog_result value);
    /// @}

  protected:
    /// @name Protected Properties
    
    /// @{
    win32::create_params create_params() const noexcept override;

    SIZE default_size() const noexcept override;
    /// @}

    /// @name Protected Methods

    /// @{
    void wnd_proc(message& message) override;
    /// @}

  private:
    void wm_command_control(win32::message& message);

    struct data {
      win32::dialog_result dialog_result = win32::dialog_result::none;
    };
    std::shared_ptr<data> data_ = std::make_shared<data>();
  };
}