#pragma once
#include <Windows.h>
#include "color.h"

namespace win32 {
  /// @brief Each property of the win32::system_colors class is a win32::color structure that is the color of a Windows display element.
  /// @remarks Better performance is achieved by using the properties of the win32::system_pens or win32::system_brushes classes rather than creating a new pen or brush based on a value from win32::system_colors. For example, if you wanted to get a brush for the face color of a 3-D element, use the SystemBrushes.Control property because it gets a brush that already exists, whereas calling the SolidBrush.#ctor(xtd::drawing::color) constructor with a parameter value of system_colors::Control will create a new brush.
  class system_colors final {
  public:
    /// @name Properties

    /// @{
    /// @brief Gets a xtd::drawing::color structure that is the color used to accent a control.
    /// @return A xtd::drawing::color that is the color used to accent a control.
    static win32::color accent();

    /// @brief Gets a xtd::drawing::color structure that is the color of the text used to accent a control.
    /// @return A xtd::drawing::color that is the color of the text used to accent a control.
    static win32::color accent_text();

    /// @brief Gets a xtd::drawing::color structure that is the color of the active window's border.
    /// @return A xtd::drawing::color that is the color of the active window's border.
    static win32::color active_border();

    /// @brief Gets a xtd::drawing::color structure that is the color of the background of the active window's title bar.
    /// @return A xtd::drawing::color that is the color of the active window's title bar.
    static win32::color active_caption();

    /// @brief Gets a xtd::drawing::color structure that is the color of the text in the active window's title bar.
    /// @return A xtd::drawing::color that is the color of the text in the active window's title bar.
    static win32::color active_caption_text();

    /// @brief Gets a xtd::drawing::color structure that is the color of the application workspace.
    /// @return A xtd::drawing::color that is the color of the application workspace.
    /// @remarks The application workspace is the area in a multiple-document view that is not being occupied by documents.
    static win32::color app_workspace();

    /// @brief Gets a xtd::drawing::color structure that is the face color of a 3-D element.
    /// @return A xtd::drawing::color that is the face color of a 3-D element.
    static win32::color button_face();

    /// @brief Gets a xtd::drawing::color structure that is the highlight color of a 3-D element.
    /// @return A xtd::drawing::color that is the highlight color of a 3-D element.
    /// @remarks This color is applied to parts of a 3-D element that face the light source.
    static win32::color button_highlight();

    /// @brief Gets a xtd::drawing::color structure that is the shadow color of a 3-D element.
    /// @return A xtd::drawing::color that is the shadow color of a 3-D element.
    /// @remarks This color is applied to parts of a 3-D element that face away from the light source.
    static win32::color button_shadow();

    /// @brief Gets a xtd::drawing::color structure that is the face color of a 3-D element.
    /// @return A xtd::drawing::color that is the face color of a 3-D element.
    static win32::color control();

    /// @brief Gets a xtd::drawing::color structure that is the shadow color of a 3-D element.
    /// @return A xtd::drawing::color that is the shadow color of a 3-D element.
    /// @remarks This color is applied to parts of a 3-D element that face away from the light source.
    static win32::color control_dark();

    /// @brief Gets a xtd::drawing::color structure that is the dark shadow color of a 3-D element.
    /// @return A xtd::drawing::color that is the dark shadow color of a 3-D element.
    /// @remarks This color is applied to the parts of a 3-D element that are the darkest color.
    static win32::color control_dark_dark();

    /// @brief Gets a xtd::drawing::color structure that is the light color of a 3-D element.
    /// @return A xtd::drawing::color that is the light color of a 3-D element.
    /// @remarks This color is applied to parts of a 3-D element that face the light source.
    static win32::color control_light();

    /// @brief Gets a xtd::drawing::color structure that is the highlight color of a 3-D element.
    /// @return A xtd::drawing::color that is the highlight color of a 3-D element.
    /// @remarks This color is applied to the parts of a 3-D element that are the lightest color.
    static win32::color control_light_light();

    /// @brief Gets a xtd::drawing::color structure that is the color of text in a 3-D element.
    /// @return A xtd::drawing::color that is the color of text in a 3-D element.
    static win32::color control_text();

    /// @brief Gets a xtd::drawing::color structure that is the color of the desktop.
    /// @return A xtd::drawing::color that is the color of the desktop.
    static win32::color desktop();

    /// @brief Gets a xtd::drawing::color structure that is the lightest color in the color gradient of an active window's title bar.
    /// @return A xtd::drawing::color that is the lightest color in the color gradient of an active window's title bar.
    static win32::color gradient_active_caption();

    /// @brief Gets a xtd::drawing::color structure that is the lightest color in the color gradient of an inactive window's title bar.
    /// @return A xtd::drawing::color that is the lightest color in the color gradient of an inactive window's title bar.
    static win32::color gradient_inactive_caption();

    /// @brief Gets a xtd::drawing::color structure that is the color of dimmed text.
    /// @return A xtd::drawing::color that is the color of dimmed text.
    /// @remarks Items in a list that are disabled are displayed in dimmed text.
    static win32::color gray_text();

    /// @brief Gets a xtd::drawing::color structure that is the color of the background of selected items.
    /// @return A xtd::drawing::color that is the color of the background of selected items.
    /// @remarks Selected items may include menu items as well as selected text. For example, the xtd::drawing::color structure may be the color used for the background of selected items in a list box.
    static win32::color highlight();

    /// @brief Gets a xtd::drawing::color structure that is the color of the text of selected items.
    /// @return A xtd::drawing::color that is the color of the text of selected items.
    /// @remarks For example, this color is used for the text of selected items in a list box.
    static win32::color highlight_text();

    /// @brief Gets a xtd::drawing::color structure that is the color used to designate a hot-tracked item.
    /// @return A xtd::drawing::color that is the color used to designate a hot-tracked item.
    /// @remarks Single-clicking a hot-tracked item executes the item.
    static win32::color hot_track();

    /// @brief Gets a xtd::drawing::color structure that is the color of an inactive window's border.
    /// @return A xtd::drawing::color that is the color of an inactive window's border.
    static win32::color inactive_border();

    /// @brief Gets a xtd::drawing::color structure that is the color of the background of an inactive window's title bar.
    /// @return A xtd::drawing::color that is the color of the background of an inactive window's title bar.
    static win32::color inactive_caption();

    /// @brief Gets a xtd::drawing::color structure that is the color of the text in an inactive window's title bar.
    /// @return A xtd::drawing::color that is the color of the text in an inactive window's title bar.
    static win32::color inactive_caption_text();

    /// @brief Gets a xtd::drawing::color structure that is the color of the background of a xtd::forms::tool_tip.
    /// @return A xtd::drawing::color that is the color of the background of a xtd::forms::tool_tip.
    static win32::color info();

    /// @brief Gets a xtd::drawing::color structure that is the color of the text of a xtd::forms::tool_tip.
    /// @return A xtd::drawing::color that is the color of the text of a xtd::forms::tool_tip.
    static win32::color info_text();

    /// @brief Gets a xtd::drawing::color structure that is the color of a menu's background.
    /// @return A xtd::drawing::color that is the color of a menu's background.
    static win32::color menu();

    /// @brief Gets a xtd::drawing::color structure that is the color of the background of a menu bar.
    /// @return A xtd::drawing::color that is the color of the background of a menu bar.
    static win32::color menu_bar();

    /// @brief Gets a xtd::drawing::color structure that is the color used to highlight menu items when the menu appears as a flat menu.
    /// @return A xtd::drawing::color that is the color used to highlight menu items when the menu appears as a flat menu.
    static win32::color menu_highlight();

    /// @brief Gets a xtd::drawing::color structure that is the color of a menu's text.
    /// @return A xtd::drawing::color that is the color of a menu's text.
    static win32::color menu_text();

    /// @brief Gets a xtd::drawing::color structure that is the color of the background of a scroll bar.
    /// @return A xtd::drawing::color that is the color of the background of a scroll bar.
    static win32::color scroll_bar();

    /// @brief Gets a xtd::drawing::color structure that is the color of the background of a text box.
    /// @return A xtd::drawing::color that is the color of the background of a textt box.
    static win32::color text_box();

    /// @brief Gets a xtd::drawing::color structure that is the color of the text of a text box.
    /// @return A xtd::drawing::color that is the color of the text of a text tbox.
    static win32::color text_box_text();

    /// @brief Gets a xtd::drawing::color structure that is the color of the background in the client area of a window.
    /// @return A xtd::drawing::color that is the color of the background in the client area of a window.
    static win32::color window();

    /// @brief Gets a xtd::drawing::color structure that is the color of a window frame.
    /// @return A xtd::drawing::color that is the color of a window frame.
    static win32::color window_frame();

    /// @brief Gets a xtd::drawing::color structure that is the color of the text in the client area of a window.
    /// @return A xtd::drawing::color that is the color of the text in the client area of a window.
    static win32::color window_text();
    /// @}
  };
}