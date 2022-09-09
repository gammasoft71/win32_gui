#pragma once
#include "event_args.h"
#include "virtual_key_codes.h"

namespace win32 {
  /// @brief Provides data for the key_down or key_up event.
  /// @remarks A key_event_args, which specifies the key the user pressed and whether any modifier keys (CMD, CTRL, ALT, and SHIFT) were pressed at the same time, is passed with each key_down or key_up event.
  /// @remarks The key_down event occurs when the user presses any key. The key_up event occurs when the user releases the key. Duplicate key_down events occur each time the key repeats, if the key is held down, but only one key_up event is generated when the user releases the key.
  /// @remarks The key_press event also occurs when a key is pressed. A key_press_event_args is passed with each key_press event, and specifies the character that was composed as a result of each key press.
  class key_event_args : public event_args {
  public:
    /// @name Constructors

   /// @{
    key_event_args(UINT key) : key_data(key) { }
    /// @}

    /// @brief Gets a value indicating whether the ALT key was pressed.
    /// @return true if the ALT key was pressed; otherwise, false.
    bool alt() const { return (key_data & VK_ALT_MODIFIER) == VK_ALT_MODIFIER; }

    /// @brief Gets a value indicating whether the CMD key was pressed.
    /// @return true if the CMD key was pressed; otherwise, false.
    bool command() const { return (key_data & VK_COMMAND_MODIFIER) == VK_COMMAND_MODIFIER; }

    /// @brief Gets a value indicating whether the CTRL key was pressed.
    /// @return true if the CTRL key was pressed; otherwise, false.
    bool control() const { return (key_data & VK_CONTROL_MODIFIER) == VK_CONTROL_MODIFIER; }

    /// @brief Gets the keyboard code for a key_down or key_up event.
    /// @return A xtd::forms::keys value that is the key code for the event.
    UINT key_code() const { return key_data & VK_KEY_CODE_MASK; }

    /// @brief Gets the keyboard value for a key_down or key_up event.
    /// @return The integer representation of the key_code property.
    WORD key_value() const { return static_cast<WORD>(key_data) & 0xFFFF; }

    /// @brief Gets the modifier flags for a key_down or key_up event. The flags indicate which combination of CMD, CTRL, SHIFT, and ALT keys was pressed.
    /// @return A xtd::forms::keys value representing one or more modifier flags.
    UINT modifiers() const { return key_data & VK_MODIFIERS_MASK; }

    /// @brief Gets a value indicating whether the SHIFT key was pressed.
    /// @return true if the SHIFT key was pressed; otherwise, false.
    bool shift() const { return (key_data & VK_SHIFT_MODIFIER) ==VK_SHIFT_MODIFIER; }

    /// @brief Gets or sets the key data for a key_down or key_up event.
    /// @remarks You can use constants from Keys to extract information from the key_data property. Use the bitwise AND operator to compare data returned by key_data with constants in Keys to obtain information about which keys the user pressed. To determine whether a specific modifier key was pressed, use the command, control, shift, and alt properties.
    UINT key_data = 0;
    
    /// @brief Gets or sets a value indicating whether the event was handled.
    /// @remarks handled is implemented differently by different controls within xtd.forms. For controls like text_box which subclass native Win32 controls, it is interpreted to mean that the key message should not be passed to the underlying native control. If you set handled to true on a text_box, that control will not pass the key press events to the underlying Win32 text box control, but it will still display the characters that the user typed.
    bool handled = false;

    /// @brief Gets or sets a value indicating whether the key event should be passed on to the underlying control.
    /// @remarks You can assign true to this property in an event handler such as key_down in order to prevent user input.
    /// @remarks Setting suppress_key_press to true also sets handled to true.
    bool suppress_key_press = false;
  };
}
