#include "../include/control.h"

using namespace win32;

control::~control() {
  destroy_handle();
}

COLORREF control::back_color() const noexcept {
  return data_->back_color.value_or(parent() ? parent()->get().back_color() : default_back_color());
}

control& control::back_color(COLORREF value) {
  if (!data_->back_color || data_->back_color != value) {
    data_->back_color = value;
    on_back_color_changed(event_args::empty);
  }
  return *this;
}

control& control::back_color(nullptr_t value) {
  if (data_->back_color) {
    data_->back_color.reset();
    on_back_color_changed(event_args::empty);
  }
  return *this;
}

bool control::enabled() const noexcept {
  return IsWindowEnabled(handle());
}

control& control::enabled(bool value) {
  EnableWindow(handle(), value);
  return *this;
}

COLORREF control::fore_color() const noexcept {
  return data_->fore_color.value_or(parent() ? parent()->get().fore_color() : default_fore_color());
}

control& control::fore_color(COLORREF value) {
  if (!data_->fore_color || data_->fore_color != value) {
    data_->fore_color = value;
    on_fore_color_changed(event_args::empty);
  }
  return *this;
}

control& control::fore_color(nullptr_t value) {
  if (data_->fore_color) {
    data_->fore_color.reset();
    on_fore_color_changed(event_args::empty);
  }
  return *this;
}

HWND control::handle() const noexcept {
  if (!data_->handle) const_cast<control*>(this)->create_handle();
  return data_->handle;
}

POINT control::location() const noexcept {
  return data_->location;
}

control& control::location(POINT value) {
  if (data_->location.x != value.x || data_->location.y != value.y) {
    data_->location = value;
    set_bound_core(left(), top(), width(), height(), bounds_specified::location);
  }
  return *this;
}

int control::height() const noexcept { 
  return data_->size.cy;
}

control& control::height(int value) {
  if (data_->size.cy != value) {
    data_->size.cy = value;
    set_bound_core(left(), top(), width(), height(), bounds_specified::height);
  }
  return *this;
}

std::optional<std::reference_wrapper<control>> control::parent() const noexcept {
  return from_handle(data_->parent);
}

control& control::parent(const control& value) {
  data_->parent = value.handle();
  SetParent(handle(), data_->parent);
  debug::write_line(string_format(L"%p - Add parent", handle()));
  return *this;

}
  
SIZE control::size() const noexcept {
  return data_->size; 
}

control& control::size(SIZE value) {
  if (data_->size.cx != value.cx || data_->size.cy != value.cy) {
    data_->size = value;
    set_bound_core(left(), top(), width(), height(), bounds_specified::size);
  }
  return *this;
}

std::wstring control::text() const noexcept { 
  return data_->text;
}

control& control::text(std::wstring value) {
  data_->text = value;
  SendMessage(handle(), WM_SETTEXT, 0, reinterpret_cast<LPARAM>(data_->text.c_str()));
  return *this;
}

bool control::visible() const noexcept {
  return IsWindowVisible(handle());
}

control& control::visible(bool value) noexcept {
  ShowWindow(handle(), value ? SW_SHOW : SW_HIDE);
  return *this;
}

int control::width() const noexcept {
  return data_->size.cx;
}

control& control::width(int value) {
  if (data_->size.cx != value) {
    data_->size.cx = value;
    set_bound_core(left(), top(), width(), height(), bounds_specified::width);
  }
  return *this;
}

int control::left() const noexcept {
  return data_->location.x;
}

control& control::left(int value) {
  if (data_->location.x != value) {
    data_->location = { value, top() };
    set_bound_core(value, 0, 0, 0, bounds_specified::x);
  }
  return *this;
}

int control::top() const noexcept {
  return data_->location.y;
}

control& control::top(int value) {
  if (data_->location.y != value) {
    data_->location = { left(), value };
    set_bound_core(0, value, 0, 0, bounds_specified::y);
  }
  return *this;
}


std::optional<std::reference_wrapper<control>> control::from_handle(HWND handle) noexcept {
  if (handle == nullptr) return std::nullopt;
  auto it = controls_.find(handle);
  if (it == controls_.end()) return std::nullopt;
  return *it->second;
}

void control::hide() {
  visible(false);
}
void control::show() {
  visible(true);
}

struct create_params control::create_params() const noexcept {
  ::create_params cp;
  cp.height = height();
  cp.parent = parent().has_value() ? parent().value().get().handle() : nullptr;
  cp.text = text().c_str();
  cp.width = width();
  cp.x = left();
  cp.y = top();
  return cp;
}

COLORREF control::default_back_color() const {
  return GetSysColor(COLOR_BTNFACE);
}

COLORREF control::default_fore_color() const {
  return GetSysColor(COLOR_BTNTEXT);
}

SIZE control::default_size() const noexcept {
  return { 0, 0 }; 
}

void control::create_handle() {
  struct create_params cp = this->create_params();
  if (cp.height == CW_USEDEFAULT) {
    cp.height = default_size().cy;
    data_->size.cy = cp.height;
  }
  if (cp.width == CW_USEDEFAULT) {
    cp.width = default_size().cx;
    data_->size.cx = cp.width;
  }
  data_->handle = CreateWindowEx(cp.ex_styles, cp.class_name, cp.text, cp.styles, cp.x, cp.y, cp.width, cp.height, cp.parent, nullptr, nullptr, nullptr);
  data_->def_wnd_proc = reinterpret_cast<WNDPROC>(SetWindowLongPtr(data_->handle, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(wnd_proc_dispatcher)));
  controls_[data_->handle] = this;
  debug::write_line(string_format(L"%p - create handle", data_->handle));
  on_handle_created(event_args::empty);
}

LRESULT control::def_wnd_proc(const message& message) {
  return CallWindowProc(data_->def_wnd_proc, message.hwnd, message.msg, message.wparam, message.lparam);
}

void control::destroy_handle() {
  if (!data_->handle) return;
  SetWindowLongPtr(data_->handle, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(data_->def_wnd_proc));
  DestroyWindow(data_->handle);
  controls_.erase(data_->handle);
  data_->handle = nullptr;
  on_handle_destroyed(event_args::empty);
}

void control::recreate_handle() {
  destroy_handle();
  create_handle();
}

LRESULT control::reflect_message(HWND handle, const message& message) {
  return SendMessage(handle, WM_REFLECT + message.msg, message.wparam, message.lparam);
}

void control::set_bound_core(int x, int y, int width, int height, bounds_specified specified) {
  if ((static_cast<int>(specified) & static_cast<int>(bounds_specified::x)) == static_cast<int>(bounds_specified::x) || (static_cast<int>(specified) & static_cast<int>(bounds_specified::y)) == static_cast<int>(bounds_specified::y)) {
    SetWindowPos(handle(), nullptr, left(), top(), this->width(), this->height(), SWP_NOSIZE);
    on_location_changed(event_args::empty);
  }
  if ((static_cast<int>(specified) & static_cast<int>(bounds_specified::width)) == static_cast<int>(bounds_specified::width) || (static_cast<int>(specified) & static_cast<int>(bounds_specified::height)) == static_cast<int>(bounds_specified::height)) {
    SetWindowPos(handle(), nullptr, left(), top(), this->width(), this->height(), SWP_NOMOVE);
    on_size_changed(event_args::empty);
    on_resize(event_args::empty);
  }
}

LRESULT control::wnd_proc(const message& message) {
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
  case WM_XBUTTONDOWN: return wm_mouse_down(message); break;
  case WM_LBUTTONDBLCLK:
  case WM_MBUTTONDBLCLK:
  case WM_RBUTTONDBLCLK:
  case WM_XBUTTONDBLCLK: return wm_mouse_double_click(message); break;
  case WM_LBUTTONUP:
  case WM_MBUTTONUP:
  case WM_RBUTTONUP:
  case WM_XBUTTONUP: return wm_mouse_up(message); break;
  case WM_MOUSEMOVE: wm_mouse_move(message); break;
  case WM_MOUSEENTER: wm_mouse_enter(message); break;
  case WM_MOUSELEAVE: wm_mouse_leave(message); break;
  case WM_MOUSEHWHEEL:
  case WM_MOUSEWHEEL: wm_mouse_wheel(message); break;
  // Color events
  //case WM_CTLCOLORDLG: /// @todo to process
  //case WM_CTLCOLORMSGBOX: /// @todo to process
  case WM_CTLCOLOR:
  case WM_CTLCOLORBTN:
  case WM_CTLCOLORSCROLLBAR:
  case WM_CTLCOLOREDIT:
  case WM_CTLCOLORLISTBOX:
  case WM_CTLCOLORSTATIC: return reflect_message(reinterpret_cast<HWND>(message.lparam), message); break;
  case WM_ERASEBKGND: return wm_erasebkgnd(message); break;
  // Scrolling events
  case WM_HSCROLL:
  case WM_VSCROLL: wm_scroll(message); break;
  // System events
  case WM_CHILDACTIVATE: wm_child_activate(message); break;
  case WM_COMMAND: return reflect_message(reinterpret_cast<HWND>(message.lparam), message); break;
  case WM_CREATE: wm_create(message); break;
  case WM_HELP: wm_help(message); break;
  case WM_KILLFOCUS: wm_kill_focus(message); break;
  case WM_MENUCOMMAND: wm_menu_command(message); break;
  case WM_MOVE: wm_move(message);  break;
  case WM_NOTIFY: return reflect_message(reinterpret_cast<HWND>(message.lparam), message); break;
  case WM_PAINT: wm_paint(message); break;
  case WM_SETFOCUS: wm_set_focus(message); break;
  case WM_SETTEXT: wm_set_text(message); break;
  case WM_SHOWWINDOW: wm_show(message); break;
  case WM_SIZE: wm_size(message); break;
  case WM_SIZING: wm_sizing(message); break;
  case WM_ENTERIDLE: wm_enter_idle(message); break;
  // Reflect events
  case WM_REFLECT + WM_CTLCOLOR:
  case WM_REFLECT + WM_CTLCOLORBTN:
  case WM_REFLECT + WM_CTLCOLORSCROLLBAR:
  case WM_REFLECT + WM_CTLCOLOREDIT:
  case WM_REFLECT + WM_CTLCOLORLISTBOX:
  case WM_REFLECT + WM_CTLCOLORSTATIC: return wm_ctlcolor(message); break;
  case WM_REFLECT + WM_COMMAND: return wm_command(message); break;
  case WM_REFLECT + WM_NOTIFY: wm_notify(message);  break;
  default: return def_wnd_proc(message);
  }
  return def_wnd_proc(message);
}

void control::on_click(const event_args& e) {
  if (click) click(*this, e);
}

void control::on_back_color_changed(const event_args& e) {
  if (back_color_changed) back_color_changed(*this, e);
}

void control::on_fore_color_changed(const event_args& e) {
  if (fore_color_changed) fore_color_changed(*this, e);
}

void control::on_handle_created(const event_args& e) {
}

void control::on_handle_destroyed(const event_args& e) {
}

void control::on_location_changed(const event_args& e) {
  if (location_changed) location_changed(*this, e);
}

void control::on_resize(const event_args& e) {
  if (resize) resize(*this, e);
}

void control::on_size_changed(const event_args& e) {
  if (size_changed) size_changed(*this, e);
}


LRESULT CALLBACK control::wnd_proc_dispatcher(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam) {
  auto control = from_handle(hwnd);
  if (control.has_value()) return control.value().get().wnd_proc({hwnd, message, wparam, lparam});
  return DefWindowProc(hwnd, message, wparam, lparam);
}

LRESULT control::wm_child_activate(const message& message) {
  return def_wnd_proc(message);
}

LRESULT control::wm_command(const message& message) {
  on_click(event_args::empty);
  return def_wnd_proc(message);
}

LRESULT control::wm_ctlcolor(const message& message) {
  HDC hdc = reinterpret_cast<HDC>(message.wparam);
  debug::write_line(string_format(L"%p - wm_ctlcolorstatic - back color {0x%06X}", handle(), back_color()));
  SetBkMode(hdc, TRANSPARENT);
  SetTextColor(hdc, fore_color());
  SetBkColor(hdc, back_color());

  if (data_->back_brush == nullptr)
    data_->back_brush = CreateSolidBrush(back_color());
  return reinterpret_cast<LRESULT>(data_->back_brush);
}

LRESULT control::wm_create(const message& message) {
  return def_wnd_proc(message);
}

LRESULT control::wm_enter_idle(const message& message) {
  return def_wnd_proc(message);
}

LRESULT control::wm_erasebkgnd(const message& message) {
  HDC hdc = reinterpret_cast<HDC>(message.wparam);
  RECT rect;
  GetClientRect(handle(), &rect); /// @todo findd best mthod to get rect.
  HBRUSH brush = CreateSolidBrush(back_color());
  FillRect(hdc, &rect, brush);
  DeleteObject(brush);
  return 0;
}

LRESULT control::wm_help(const message& message) {
  return def_wnd_proc(message);
}

LRESULT control::wm_key_char(const message& message) {
  return def_wnd_proc(message);
}

LRESULT control::wm_kill_focus(const message& message) {
  return def_wnd_proc(message);
}

LRESULT control::wm_menu_command(const message& message) {
  return def_wnd_proc(message);
}

LRESULT control::wm_mouse_down(const message& message) {
  return def_wnd_proc(message);
}

LRESULT control::wm_mouse_double_click(const message& message) {
  return def_wnd_proc(message);
}

LRESULT control::wm_mouse_enter(const message& message) {
  return def_wnd_proc(message);
}

LRESULT control::wm_mouse_leave(const message& message) {
  return def_wnd_proc(message);
}

LRESULT control::wm_mouse_move(const message& message) {
  return def_wnd_proc(message);
}

LRESULT control::wm_mouse_up(const message& message) {
  return def_wnd_proc(message);
}

LRESULT control::wm_mouse_wheel(const message& message) {
  return def_wnd_proc(message);
}

LRESULT control::wm_move(const message& message) {
  return def_wnd_proc(message);
}

LRESULT control::wm_notify(const message& message) {
  return def_wnd_proc(message);
}

LRESULT control::wm_paint(const message& message) {
  return def_wnd_proc(message);
}

LRESULT control::wm_scroll(const message& message) {
  return def_wnd_proc(message);
}

LRESULT control::wm_set_focus(const message& message) {
  return def_wnd_proc(message);
}

LRESULT control::wm_set_text(const message& message) {
  return def_wnd_proc(message);
}

LRESULT control::wm_show(const message& message) {
  return def_wnd_proc(message);
}

LRESULT control::wm_size(const message& message) {
  return def_wnd_proc(message);
}

LRESULT control::wm_sizing(const message& message) {
  return def_wnd_proc(message);
}
