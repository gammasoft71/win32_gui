#include "../include/dark_mode.h"
#include "../include/debug.h"
#include "../include/application.h"
#include "../include/control.h"
#include "../include/system_colors.h"
#include "../include/window_messages.h"

using namespace std;
using namespace win32;

control::control() {
  set_state(state::enabled, true);
  set_state(state::visible, true);
  set_state(state::tab_stop, true);
}

control::~control() {
  destroy_control();
}

COLORREF control::back_color() const noexcept {
  for (const control* control = this; control; control = control->parent().has_value() ? &control->parent().value().get() : nullptr)
    if (control->data_->back_color.has_value()) return control->data_->back_color.value();
  return default_back_color();
}

control& control::back_color(COLORREF value) {
  if (data_->back_color && data_->back_color == value) return *this;
  data_->back_color = value;
  on_back_color_changed(event_args::empty);
  return *this;
}

control& control::back_color(nullptr_t) {
  if (!data_->back_color) return *this;
  data_->back_color.reset();
  on_back_color_changed(event_args::empty);
  return *this;
}

int control::bottom() const noexcept {
  return top() + height();
}

RECT control::client_rectangle() const noexcept {
  RECT rect{ left(), top(), right(), bottom() };
  if (is_handle_created()) GetClientRect(handle(), &rect);
  return rect;
}

SIZE control::client_size() const noexcept {
  RECT rect = client_rectangle();
  return {rect.right - rect.left, rect.bottom - rect.top };
}

control& control::client_size(SIZE value) {
  if (data_->size.cx == value.cx && data_->size.cy == value.cy) return *this;
  RECT rect = client_rectangle();
  RECT adjusted_rect = { 0, 0, value.cx, value.cy };
  if (style() != WS_OVERLAPPED) AdjustWindowRectEx(&adjusted_rect, style(), false, data_->ex_style);
  bounds_specified specified = bounds_specified::none;
  if (rect.right != adjusted_rect.right) specified |= bounds_specified::width;
  if (rect.bottom != adjusted_rect.bottom) specified |= bounds_specified::height;
  if (specified == bounds_specified::none) return *this;
  on_client_size_changed(event_args::empty);
  set_bound_core(0, 0, adjusted_rect.right, adjusted_rect.bottom, specified);
  return *this;
}

bool control::enabled() const noexcept {
  return get_state(state::enabled);
}

control& control::enabled(bool value) {
  if (get_state(state::enabled) == value) return *this;
  if (is_handle_created()) EnableWindow(handle(), value);
  set_state(state::enabled, value);
  on_enabled_changed(event_args::empty);
  return *this;
}

COLORREF control::fore_color() const noexcept {
  for (const control* control = this; control; control = control->parent().has_value() ? &control->parent().value().get() : nullptr)
    if (control->data_->fore_color.has_value()) return control->data_->fore_color.value();
  return default_fore_color();
}

control& control::fore_color(COLORREF value) {
  if (data_->fore_color && data_->fore_color == value) return *this;
  data_->fore_color = value;
  on_fore_color_changed(event_args::empty);
  return *this;
}

control& control::fore_color(nullptr_t value) {
  if (!data_->fore_color) return *this;
  data_->fore_color.reset();
  on_fore_color_changed(event_args::empty);
  return *this;
}

HWND control::handle() const noexcept {
  return data_->handle;
}

int control::height() const noexcept { 
  return data_->size.cy;
}

control& control::height(int value) {
  if (data_->size.cy == value) return *this;
  data_->size.cy = value;
  set_bound_core(left(), top(), width(), height(), bounds_specified::height);
  return *this;
}

int control::left() const noexcept {
  return data_->location.x;
}

control& control::left(int value) {
  if (data_->location.x == value) return *this;
  data_->location = { value, top() };
  set_bound_core(value, 0, 0, 0, bounds_specified::x);
  return *this;
}

POINT control::location() const noexcept {
  return data_->location;
}

control& control::location(POINT value) {
  bounds_specified specified = bounds_specified::none;
  if (data_->location.x != value.x || data_->location.y != value.y) specified |= bounds_specified::x;
  if (data_->location.x != value.x || data_->location.y != value.y) specified |= bounds_specified::x;
  data_->location = value;
  if (specified != bounds_specified::none) set_bound_core(left(), top(), width(), height(), specified);
  return *this;
}

UINT control::modifier_keys() {
  return modifier_keys_;
}


std::optional<std::reference_wrapper<control>> control::parent() const noexcept {
  return from_handle(data_->parent);
}

control& control::parent(const control& value) {
  if (value.handle() != data_->parent) {
    if (parent().has_value()) this->parent(nullptr);
    else on_parent_changed(event_args::empty);
    if (value.is_handle_created()) const_cast<control&>(value).data_->controls.push_back(*this);
  } else if (!value.is_handle_created())
    const_cast<control&>(value).data_->controls.push_back(*this);
  data_->parent = value.handle();
  if (value.is_handle_created()) create_control();
  return *this;
}

control& control::parent(nullptr_t) {
  if (!is_handle_created() || data_->parent == nullptr) return *this;
  auto current_parent = from_handle(data_->parent);
  for (auto it = current_parent.value().get().data_->controls.begin(); it != current_parent.value().get().data_->controls.end(); ++it) {
    if (it->get().handle() != handle()) continue;
    auto prev_parent = parent();
    on_parent_changed(event_args::empty);
    parent().value().get().data_->controls.erase(it);
    destroy_control();
    if (!get_state(state::destroying) && !prev_parent.value().get().get_state(state::destroying)) prev_parent.value().get().refresh();
    break;
  }
return *this;
}

int control::right() const noexcept {
  return left() + width();
}

SIZE control::size() const noexcept {
  return data_->size; 
}

control& control::size(SIZE value) {
  bounds_specified specified = bounds_specified::none;
  if (data_->size.cx != value.cx) specified |= bounds_specified::width;
  if (data_->size.cy != value.cy) specified |= bounds_specified::height;
  data_->size = value;
  if (specified != bounds_specified::none) set_bound_core(left(), top(), width(), height(), specified);
  return *this;
}

const std::wstring& control::text() const noexcept { 
  return data_->text;
}

control& control::text(std::wstring value) {
  if (data_->text == value) return *this;
  data_->text = value;
  if (is_handle_created()) SendMessage(handle(), WM_SETTEXT, 0, reinterpret_cast<LPARAM>(data_->text.c_str()));
  on_text_changed(event_args::empty);
  return *this;
}

int control::top() const noexcept {
  return data_->location.y;
}

control& control::top(int value) {
  if (data_->location.y == value) return *this;
  data_->location = { left(), value };
  set_bound_core(0, value, 0, 0, bounds_specified::y);
  return *this;
}

bool control::visible() const noexcept {
  return get_state(state::visible);
}

control& control::visible(bool value) noexcept {
  if (get_state(state::visible) == value) return *this;
  if (is_handle_created()) ShowWindow(handle(), value ? SW_SHOW : SW_HIDE);
  set_state(state::visible, value);
  on_visible_changed(event_args::empty);
  return *this;
}

int control::width() const noexcept {
  return data_->size.cx;
}

control& control::width(int value) {
  if (data_->size.cx == value) return *this;
  data_->size.cx = value;
  set_bound_core(left(), top(), width(), height(), bounds_specified::width);
  return *this;
}

void control::create_control() {
  if (get_state(state::created) || get_state(state::creating) || get_state(state::destroying)) return;
  set_state(state::destroyed, false);
  set_state(state::creating, true);
  
  create_handle();
  
  set_state(state::created, is_handle_created());
  set_state(state::creating, false);
}

void control::destroy_control() {
  if (!get_state(state::created)) return;
  set_state(state::created, false);
  set_state(state::destroying, true);

  if (is_handle_created())
    destroy_handle();
  
  set_state(state::destroyed, true);
  set_state(state::destroying, false);
}

std::optional<std::reference_wrapper<control>> control::from_child_handle(HWND handle) noexcept {
  try {
    auto it = handles_.find(handle);
    if (it != handles_.end())
      return it->second->parent();
    return nullopt;
  } catch (...) {
    return nullopt;
  }
}

std::optional<std::reference_wrapper<control>> control::from_handle(HWND handle) noexcept {
  try {
    auto it = handles_.find(handle);
    if (it != handles_.end())
      return *it->second;
    return nullopt;
  } catch (...) {
    return nullopt;
  }
}

void control::hide() {
  visible(false);
}

void control::invalidate() const {
  if (is_handle_created()) RedrawWindow(handle(), nullptr, nullptr, RDW_INVALIDATE | RDW_NOCHILDREN);
}

void control::invalidate(bool invalidate_children) const {
  if (is_handle_created()) RedrawWindow(handle(), nullptr, nullptr, RDW_INVALIDATE | (invalidate_children ? RDW_ALLCHILDREN : RDW_NOCHILDREN));
}

void control::invalidate(RECT rect) const {
  if (is_handle_created()) RedrawWindow(handle(), &rect, nullptr, RDW_INVALIDATE | RDW_NOCHILDREN);
}

void control::invalidate(RECT rect, bool invalidate_children) const {
  if (is_handle_created()) RedrawWindow(handle(), &rect, nullptr, RDW_INVALIDATE | (invalidate_children ? RDW_ALLCHILDREN : RDW_NOCHILDREN));
}

void control::invalidate(HRGN region) const {
  if (is_handle_created()) RedrawWindow(handle(), nullptr, region, RDW_INVALIDATE | RDW_NOCHILDREN);
}

void control::invalidate(HRGN region, bool invalidate_children) const {
  if (is_handle_created()) RedrawWindow(handle(), nullptr, region, RDW_INVALIDATE | (invalidate_children ? RDW_ALLCHILDREN : RDW_NOCHILDREN));
}

bool control::is_handle_created() const noexcept {
  return data_->handle != nullptr;
}

void control::refresh() const {
  invalidate(true);
  update();
}

void control::show() {
  visible(true);
}

void control::update() const {
  if (is_handle_created())UpdateWindow(handle());
}

win32::create_params control::create_params() const noexcept {
  win32::create_params cp;
  cp.class_name = WC_DIALOG;
  cp.height = height();
  cp.parent = parent().has_value() ? parent().value().get().handle() : nullptr;
  cp.text = text().c_str();
  cp.width = width();
  cp.x = left();
  cp.y = top();
  if (!get_state(state::enabled)) cp.style |= WS_DISABLED;
  if (get_state(state::tab_stop)) cp.style |= WS_TABSTOP;
  if (get_state(state::visible)) cp.style |= WS_VISIBLE;
  return cp;
}

COLORREF control::default_back_color() const {
  return system_colors::control();
}

COLORREF control::default_fore_color() const {
  return system_colors::control_text();
}

SIZE control::default_size() const noexcept {
  return { 0, 0 }; 
}

DWORD control::ex_style() const {
  return data_->ex_style;
}

DWORD control::style() const {
  return data_->style;
}

void control::create_handle() {
  if (is_handle_created()) return;
  set_state(state::creating_handle, true);
  application::set_dark_mode();
  struct create_params cp = this->create_params();
  if (cp.height == CW_USEDEFAULT) {
    cp.height = default_size().cy;
    data_->size.cy = cp.height;
  }
  if (cp.width == CW_USEDEFAULT) {
    cp.width = default_size().cx;
    data_->size.cx = cp.width;
  }
  data_->ex_style = cp.ex_style;
  data_->style = cp.style;
  data_->handle = CreateWindowEx(cp.ex_style, cp.class_name, cp.text, cp.style, cp.x, cp.y, cp.width, cp.height, cp.parent, nullptr, nullptr, nullptr);
  data_->def_wnd_proc = reinterpret_cast<WNDPROC>(SetWindowLongPtr(data_->handle, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(wnd_proc_)));
  handles_[data_->handle] = this;
  dark_mode::allow_dark_mode_for_window(data_->handle);
  dark_mode::refresh_title_bar_theme_color(data_->handle);
  //debug::write_line(string_format(L"%p - create handle", data_->handle));
  set_state(state::creating_handle, false);
  on_handle_created(event_args::empty);
}

void control::def_wnd_proc(message& message) {
  message.result = CallWindowProc(data_->def_wnd_proc, message.hwnd, message.msg, message.wparam, message.lparam);
}

void control::destroy_handle() {
  if (!is_handle_created()) return;
  SetWindowLongPtr(data_->handle, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(data_->def_wnd_proc));
  DestroyWindow(data_->handle);
  handles_.erase(data_->handle);
  data_->handle = nullptr;
  on_handle_destroyed(event_args::empty);
}

void control::on_click(const event_args& e) {
  click(*this, e);
}

void control::on_back_color_changed(const event_args& e) {
  back_color_changed(*this, e);
}

void control::on_client_size_changed(const event_args& e) {
  client_size_changed(*this, e);
}

void control::on_enabled_changed(const event_args& e) {
  enabled_changed(*this, e);
}

void control::on_fore_color_changed(const event_args& e) {
  fore_color_changed(*this, e);
}

void control::on_handle_created(const event_args& e) {
  refresh();
}

void control::on_handle_destroyed(const event_args& e) {

}

void control::on_key_down(key_event_args& e) {
  key_down(*this, e);
}

void control::on_key_press(key_press_event_args& e) {
  key_press(*this, e);
}

void control::on_key_up(key_event_args& e) {
  key_up(*this, e);
}

void control::on_location_changed(const event_args& e) {
  location_changed(*this, e);
}

void control::on_parent_changed(const event_args& e) {
  parent_changed(*this, e);
}

void control::on_resize(const event_args& e) {
  resize(*this, e);
}

void control::on_size_changed(const event_args& e) {
  size_changed(*this, e);
}

void control::on_text_changed(const event_args& e) {
  text_changed(*this, e);
}

void control::on_visible_changed(const event_args& e) {
  visible_changed(*this, e);
}

void control::recreate_handle() {
  destroy_handle();
  create_handle();
}

void control::reflect_message(HWND handle, message& message) {
  message.result = SendMessage(handle, WM_REFLECT + message.msg, message.wparam, message.lparam);
}

void control::set_bound_core(int x, int y, int width, int height, bounds_specified specified) {
  if ((specified & bounds_specified::x) == bounds_specified::x || (specified & bounds_specified::y) == bounds_specified::y) {
    if (is_handle_created()) SetWindowPos(handle(), nullptr, left(), top(), this->width(), this->height(), SWP_NOSIZE);
    on_location_changed(event_args::empty);
  }
  if ((specified & bounds_specified::width) == bounds_specified::width || (specified & bounds_specified::height) == bounds_specified::height) {
    if (is_handle_created()) SetWindowPos(handle(), nullptr, left(), top(), this->width(), this->height(), SWP_NOMOVE);
    on_size_changed(event_args::empty);
    on_resize(event_args::empty);
  }
}

void control::wnd_proc(message& message) {
  switch (message.msg) {
  // Keuboard events
  case WM_CHAR:
  case WM_KEYDOWN:
  case WM_KEYUP:
  case WM_SYSCHAR:
  case WM_SYSKEYDOWN:
  case WM_SYSKEYUP: wm_key_char(message); break;
  // Mouse events
  case WM_LBUTTONDOWN:
  case WM_MBUTTONDOWN:
  case WM_RBUTTONDOWN:
  case WM_XBUTTONDOWN: wm_mouse_down(message); break;
  case WM_LBUTTONDBLCLK:
  case WM_MBUTTONDBLCLK:
  case WM_RBUTTONDBLCLK:
  case WM_XBUTTONDBLCLK: wm_mouse_double_click(message); break;
  case WM_LBUTTONUP:
  case WM_MBUTTONUP:
  case WM_RBUTTONUP:
  case WM_XBUTTONUP: wm_mouse_up(message); break;
  case WM_MOUSEMOVE: wm_mouse_move(message); break;
  case WM_MOUSEENTER: wm_mouse_enter(message); break;
  case WM_MOUSELEAVE: wm_mouse_leave(message); break;
  case WM_MOUSEHWHEEL:
  case WM_MOUSEWHEEL: wm_mouse_wheel(message); break;
  // Color events
  case WM_CTLCOLOR:
  case WM_CTLCOLORBTN:
  case WM_CTLCOLORDLG:
  case WM_CTLCOLOREDIT:
  case WM_CTLCOLORLISTBOX:
  case WM_CTLCOLORMSGBOX:
  case WM_CTLCOLORSCROLLBAR:
  case WM_CTLCOLORSTATIC: wm_ctlcolor(message); break;
  case WM_ERASEBKGND: wm_erasebkgnd(message); break;
  // Scrolling events
  case WM_HSCROLL:
  case WM_VSCROLL: wm_scroll(message); break;
  // System events
  case WM_CHILDACTIVATE: wm_child_activate(message); break;
  case WM_COMMAND: wm_command(message); break;
  case WM_CREATE: wm_create(message); break;
  case WM_HELP: wm_help(message); break;
  case WM_KILLFOCUS: wm_kill_focus(message); break;
  case WM_MENUCOMMAND: wm_menu_command(message); break;
  case WM_MOVE: wm_move(message);  break;
  case WM_NOTIFY: wm_notify(message); break;
  case WM_PAINT: wm_paint(message); break;
  case WM_SETFOCUS: wm_set_focus(message); break;
  case WM_SETTEXT: wm_set_text(message); break;
  case WM_SHOWWINDOW: wm_show(message); break;
  case WM_SIZE: wm_size(message); break;
  case WM_SIZING: wm_sizing(message); break;
  case WM_ENTERIDLE: wm_enter_idle(message); break;
  case WM_DROPFILES: wm_drop_files(message); break;
  // Reflect events
  case WM_REFLECT + WM_CTLCOLOR:
  case WM_REFLECT + WM_CTLCOLORBTN:
  case WM_REFLECT + WM_CTLCOLORSCROLLBAR:
  case WM_REFLECT + WM_CTLCOLOREDIT:
  case WM_REFLECT + WM_CTLCOLORLISTBOX:
  case WM_REFLECT + WM_CTLCOLORSTATIC: wm_ctlcolor_control(message); break;
  case WM_REFLECT + WM_COMMAND: wm_command_control(message); break;
  case WM_REFLECT + WM_NOTIFY: wm_notify_control(message);  break;
  case WM_REFLECT + WM_HSCROLL:
  case WM_REFLECT + WM_VSCROLL: wm_scroll_control(message); break;
  default: def_wnd_proc(message);
  }
}

bool control::get_state(control::state flag) const {
  return ((int32_t)data_->state & (int32_t)flag) == (int32_t)flag;
}

void control::set_state(control::state flag, bool value) {
  data_->state = static_cast<control::state>(value ? (static_cast<int32_t>(data_->state) | static_cast<int32_t>(flag)) : (static_cast<int32_t>(data_->state) & ~static_cast<int32_t>(flag)));
}

LRESULT CALLBACK control::wnd_proc_(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
  win32::message message = { hwnd, msg, wparam, lparam, 0 };
  auto control = from_handle(hwnd);
  if (msg == WM_ACTIVATEAPP) application::wnd_proc(message);
  else if (!control.has_value()) return DefWindowProc(hwnd, msg, wparam, lparam);
  else control.value().get().wnd_proc(message);
  return message.result;
}

void control::wm_child_activate(message& message) {
  def_wnd_proc(message);
}

void control::wm_command(message& message) {
  def_wnd_proc(message);
  reflect_message(reinterpret_cast<HWND>(message.lparam), message);
}

void control::wm_command_control(message& message) {
  def_wnd_proc(message);
}

void control::wm_ctlcolor(message& message) {
  def_wnd_proc(message);
  reflect_message(reinterpret_cast<HWND>(message.lparam), message);
}

void control::wm_ctlcolor_control(message& message) {
  HDC hdc = reinterpret_cast<HDC>(message.wparam);
  //debug::write_line(string_format(L"%p - wm_ctlcolorstatic - back color {0x%06X}", handle(), back_color()));
  SetBkMode(hdc, TRANSPARENT);
  SetTextColor(hdc, fore_color());
  SetBkColor(hdc, back_color());

  if (data_->back_brush == nullptr) data_->back_brush = CreateSolidBrush(back_color());
  message.result = reinterpret_cast<LRESULT>(data_->back_brush);
}

void control::wm_create(message& message) {
  def_wnd_proc(message);
}

void control::wm_enter_idle(message& message) {
  def_wnd_proc(message);
}

void control::wm_drop_files(message& message) {
  def_wnd_proc(message);
}

void control::wm_erasebkgnd(message& message) {
  HDC hdc = reinterpret_cast<HDC>(message.wparam);
  RECT rect = client_rectangle(); /// @todo findd best mthod to get rect.
  HBRUSH brush = CreateSolidBrush(back_color());
  FillRect(hdc, &rect, brush);
  DeleteObject(brush);
}

void control::wm_help(message& message) {
  def_wnd_proc(message);
}

namespace {
  UINT get_modifier_keys() {
    UINT modifier_keys = 0;
    modifier_keys |= ((GetKeyState(VK_ALT) & 0x0100) == 0x0100 ? VK_ALT_MODIFIER : 0);
    modifier_keys |= ((GetKeyState(VK_CONTROL) & 0x0100) == 0x0100 ? VK_CONTROL_MODIFIER : 0);
    modifier_keys |= ((GetKeyState(VK_LCONTROL) & 0x0100) == 0x0100 ? VK_CONTROL_MODIFIER : 0);
    modifier_keys |= ((GetKeyState(VK_RCONTROL) & 0x0100) == 0x0100 ? VK_CONTROL_MODIFIER : 0);
    modifier_keys |= ((GetKeyState(VK_SHIFT) & 0x0100) == 0x0100 ? VK_SHIFT_MODIFIER : 0);
    modifier_keys |= ((GetKeyState(VK_LSHIFT) & 0x0100) == 0x0100 ? VK_SHIFT_MODIFIER : 0);
    modifier_keys |= ((GetKeyState(VK_RSHIFT) & 0x0100) == 0x0100 ? VK_SHIFT_MODIFIER : 0);
    modifier_keys |= ((GetKeyState(VK_LWIN) & 0x0100) == 0x0100 ? VK_META_MODIFIER : 0);
    modifier_keys |= ((GetKeyState(VK_LWIN) & 0x0100) == 0x0100 ? VK_META_MODIFIER : 0);
    return modifier_keys;
  }
}

void control::wm_key_char(message& message) {
  UINT key = static_cast<UINT>(message.wparam) + get_modifier_keys();
  if (message.msg == WM_KEYDOWN || message.msg == WM_SYSKEYDOWN) {
    win32::key_event_args key_event_args(key);
    modifier_keys_ = key_event_args.modifiers();
    on_key_down(key_event_args);
    message.result = key_event_args.suppress_key_press;
    if (!key_event_args.handled) def_wnd_proc(message);
  } else if ((message.msg == WM_CHAR || message.msg == WM_SYSCHAR) && (((key & VK_KEY_CODE_MASK) > 255U) || (std::iscntrl(static_cast<int32_t>(key & VK_KEY_CODE_MASK)))) == 0) {
    key_press_event_args key_press_event_args(static_cast<wchar_t>(key));
    on_key_press(key_press_event_args);
    message.result = key_press_event_args.handled;
    if (!key_press_event_args.handled) def_wnd_proc(message);
  } else if (message.msg == WM_KEYUP || message.msg == WM_SYSKEYUP) {
    key_event_args key_event_args(key);
    modifier_keys_ = key_event_args.modifiers();
    on_key_up(key_event_args);
    message.result = key_event_args.handled;
    if (!key_event_args.handled) def_wnd_proc(message);
  } else
    def_wnd_proc(message);
}

void control::wm_kill_focus(message& message) {
  def_wnd_proc(message);
}

void control::wm_menu_command(message& message) {
  def_wnd_proc(message);
}

void control::wm_mouse_down(message& message) {
  def_wnd_proc(message);
}

void control::wm_mouse_double_click(message& message) {
  def_wnd_proc(message);
}

void control::wm_mouse_enter(message& message) {
  def_wnd_proc(message);
}

void control::wm_mouse_leave(message& message) {
  def_wnd_proc(message);
}

void control::wm_mouse_move(message& message) {
  def_wnd_proc(message);
}

void control::wm_mouse_up(message& message) {
  def_wnd_proc(message);
}

void control::wm_mouse_wheel(message& message) {
  def_wnd_proc(message);
}

void control::wm_move(message& message) {
  def_wnd_proc(message);
}

void control::wm_notify(message& message) {
  def_wnd_proc(message);
  reflect_message(reinterpret_cast<HWND>(reinterpret_cast<NMHDR*>(message.lparam)->hwndFrom), message);
}

void control::wm_notify_control(message& message) {
  def_wnd_proc(message);
}

void control::wm_paint(message& message) {
  def_wnd_proc(message);
}

void control::wm_scroll(message& message) {
  def_wnd_proc(message);
  reflect_message(reinterpret_cast<HWND>(message.lparam), message);
}

void control::wm_scroll_control(message& message) {
  def_wnd_proc(message);
}

void control::wm_set_focus(message& message) {
  def_wnd_proc(message);
}

void control::wm_set_text(message& message) {
  def_wnd_proc(message);
}

void control::wm_show(message& message) {
  def_wnd_proc(message);
}

void control::wm_size(message& message) {
  def_wnd_proc(message);
}

void control::wm_sizing(message& message) {
  def_wnd_proc(message);
}
