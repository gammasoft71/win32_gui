#include "../../../include/win32/forms/application.h"
#include "../../../include/win32/drawing/system_colors.h"

using namespace win32;
using namespace win32::drawing;
using namespace win32::forms;

color system_colors::active_border() {
  return application::dark_mode_enabled() ? color{ 0x2C, 0x2C, 0x2C, 0xFF } : color::from_colorref(GetSysColor(COLOR_ACTIVEBORDER));
}

color system_colors::active_caption() {
  return application::dark_mode_enabled() ? color{ 0x00, 0x00, 0x00, 0xFF } : color::from_colorref(GetSysColor(COLOR_ACTIVECAPTION));
}

color system_colors::active_caption_text() {
  return application::dark_mode_enabled() ? color{ 0xFF, 0xFF, 0xFF, 0xFF } : color::from_colorref(GetSysColor(COLOR_CAPTIONTEXT));
}

color system_colors::app_workspace() {
  return application::dark_mode_enabled() ? color{ 0x19, 0x19, 0x19, 0xFF } : color::from_colorref(GetSysColor(COLOR_APPWORKSPACE));
}

color system_colors::control() {
  return application::dark_mode_enabled() ? color{ 0x19, 0x19, 0x19, 0xFF } : color::from_colorref(GetSysColor(COLOR_BTNFACE));
}

color system_colors::control_dark() {
  return application::dark_mode_enabled() ? color{ 0x23, 0x23, 0x23, 0xFF } : color::from_colorref(GetSysColor(COLOR_BTNSHADOW));
}

color system_colors::control_dark_dark() {
  return application::dark_mode_enabled() ? color{ 0x17, 0x17, 0x17, 0xFF } : color::from_colorref(GetSysColor(COLOR_3DDKSHADOW));
}

color system_colors::control_light() {
  return application::dark_mode_enabled() ? color{ 0x4A, 0x4A, 0x4A, 0xFF } : color::from_colorref(GetSysColor(COLOR_BTNHIGHLIGHT));
}

color system_colors::control_light_light() {
  return application::dark_mode_enabled() ? color{ 0x4A, 0x4A, 0x4A, 0xFF } : color::from_colorref(GetSysColor(COLOR_3DLIGHT));
}

color system_colors::control_text() {
  return application::dark_mode_enabled() ? color{ 0xFF, 0xFF, 0xFF, 0xFF } : color::from_colorref(GetSysColor(COLOR_BTNTEXT));
}

color system_colors::desktop() {
  return application::dark_mode_enabled() ? color{ 0x00, 0x78, 0xD7, 0xFF } : color::from_colorref(GetSysColor(COLOR_DESKTOP));
}

color system_colors::gray_text() {
  return application::dark_mode_enabled() ? color{ 0x6B, 0x6B, 0x6B, 0xFF } : color::from_colorref(GetSysColor(COLOR_GRAYTEXT));
}

color system_colors::highlight() {
  return application::dark_mode_enabled() ? color{ 0x4D, 0x4D, 0x4D, 0xFF } : color::from_colorref(GetSysColor(COLOR_HIGHLIGHT));
}

color system_colors::highlight_text() {
  return application::dark_mode_enabled() ? color{ 0xFF, 0xFF, 0xFF, 0xFF } : color::from_colorref(GetSysColor(COLOR_HIGHLIGHTTEXT));
}

color system_colors::hot_track() {
  return application::dark_mode_enabled() ? color{ 0x4D, 0x4D, 0x4D, 0xFF } : color::from_colorref(GetSysColor(COLOR_HOTLIGHT));
}

color system_colors::inactive_border() {
  return application::dark_mode_enabled() ? color{ 0x41, 0x41, 0x43, 0xFF } : color::from_colorref(GetSysColor(COLOR_INACTIVEBORDER));
}

color system_colors::inactive_caption() {
  return application::dark_mode_enabled() ? color{ 0x49, 0x49, 0x49, 0xFF } : color::from_colorref(GetSysColor(COLOR_INACTIVECAPTION));
}

color system_colors::inactive_caption_text() {
  return application::dark_mode_enabled() ? color{ 0x49, 0x49, 0x49, 0xFF } : color::from_colorref(GetSysColor(COLOR_INACTIVECAPTIONTEXT));
}

color system_colors::info() {
  return application::dark_mode_enabled() ? color{ 0x2B, 0x2B, 0x2B, 0xFF } : color::from_colorref(GetSysColor(COLOR_INFOBK));
}

color system_colors::info_text() {
  return application::dark_mode_enabled() ? color{ 0xFF, 0xFF, 0xFF, 0xFF } : color::from_colorref(GetSysColor(COLOR_INFOTEXT));
}

color system_colors::menu() {
  return application::dark_mode_enabled() ? color{ 0x2B, 0x2B, 0x2B, 0xFF } : color::from_colorref(GetSysColor(COLOR_MENU));
}

color system_colors::menu_text() {
  return application::dark_mode_enabled() ? color{ 0xFF, 0xFF, 0xFF, 0xFF } : color::from_colorref(GetSysColor(COLOR_MENUTEXT));
}

color system_colors::scroll_bar() {
  return application::dark_mode_enabled() ? color{ 0x17, 0x17, 0x17, 0xFF } : color::from_colorref(GetSysColor(COLOR_SCROLLBAR));
}

color system_colors::window() {
  return application::dark_mode_enabled() ? color{ 0x20, 0x20, 0x20, 0xFF } : color::from_colorref(GetSysColor(COLOR_WINDOW));
}

color system_colors::window_frame() {
  return application::dark_mode_enabled() ? color{ 0x33, 0x33, 0x33, 0xFF } : color::from_colorref(GetSysColor(COLOR_WINDOWFRAME));
}

color system_colors::window_text() {
  return application::dark_mode_enabled() ? color{ 0xFF, 0xFF, 0xFF, 0xFF } : color::from_colorref(GetSysColor(COLOR_WINDOWTEXT));
}

color system_colors::button_face() {
  return application::dark_mode_enabled() ? color{ 0x35, 0x35, 0x35, 0xFF } : color::from_colorref(GetSysColor(COLOR_BTNFACE));
}

color system_colors::button_highlight() {
  return application::dark_mode_enabled() ? color{ 0x00, 0xA0, 0xFA, 0xFF } : color::from_colorref(GetSysColor(COLOR_BTNHIGHLIGHT));
}

color system_colors::button_shadow() {
  return application::dark_mode_enabled() ? color{ 0x23, 0x23, 0x23, 0xFF } : color::from_colorref(GetSysColor(COLOR_BTNSHADOW));
}

color system_colors::gradient_active_caption() {
  return application::dark_mode_enabled() ? color{ 0x00, 0x00, 0x00, 0xFF } : color::from_colorref(GetSysColor(COLOR_GRADIENTACTIVECAPTION));
}

color system_colors::gradient_inactive_caption() {
  return application::dark_mode_enabled() ? color{ 0x2B, 0x2B, 0x2B, 0xFF } : color::from_colorref(GetSysColor(COLOR_GRADIENTINACTIVECAPTION));
}

color system_colors::menu_bar() {
  return application::dark_mode_enabled() ? color{ 0x00, 0x00, 0x00, 0xFF } : color::from_colorref(GetSysColor(COLOR_MENUBAR));
}

color system_colors::menu_highlight() {
  return application::dark_mode_enabled() ? color{ 0x33, 0x99, 0xFF, 0xFF } : color::from_colorref(GetSysColor(COLOR_MENUHILIGHT));
}

color system_colors::accent() {
  return application::dark_mode_enabled() ? color{ 0x00, 0xA0, 0xFA, 0xFF } : color::from_colorref(0xD2E8F8);
}

color system_colors::accent_text() {
  return application::dark_mode_enabled() ? color{ 0xFF, 0xFF, 0xFF, 0xFF } : color::from_colorref(GetSysColor(COLOR_HIGHLIGHTTEXT));
}

color system_colors::text_box() {
  return application::dark_mode_enabled() ? color{ 0x12, 0x12, 0x12, 0xFF } : color::from_colorref(GetSysColor(COLOR_WINDOW));
}

color system_colors::text_box_text() {
  return application::dark_mode_enabled() ? color{ 0xFF, 0xFF, 0xFF, 0xFF } : color::from_colorref(GetSysColor(COLOR_WINDOWTEXT));
}
