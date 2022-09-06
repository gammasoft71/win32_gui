#pragma once
#include "bounds_specified.h"
#include "create_params.h"
#include "event_handler.h"
#include "iwin32_window.h"
#include "message.h"
#include "string.h"
#include <map>
#include <optional>
#include <Windowsx.h>
#include <Uxtheme.h>

namespace win32 {
  /// @cond
  class control;
  using control_ref = std::reference_wrapper<control>;
  /// @endcond

  class control : public iwin32_window {
  public:
    /// @name Constructors
    /// @{

    control() = default;
    control(const control&) = delete;
    control(control&&) = delete;
    /// @}

    /// @cond
    ~control();
    /// @endcond

    /// @name Properties
    /// @{

    virtual COLORREF back_color() const noexcept;
    virtual control& back_color(COLORREF value);
    virtual control& back_color(nullptr_t value);

    virtual bool enabled() const noexcept;
    virtual control& enabled(bool value);

    virtual COLORREF fore_color() const noexcept;
    virtual control& fore_color(COLORREF value);
    virtual control& fore_color(nullptr_t value);

    virtual HWND handle() const noexcept;

    virtual POINT location() const noexcept;
    virtual control& location(POINT value);

    virtual int height() const noexcept;
    virtual control& height(int value);

    virtual std::optional<control_ref> parent() const noexcept;
    virtual control& parent(const control& value);

    virtual SIZE size() const noexcept;
    virtual control& size(SIZE value);

    virtual std::wstring text() const noexcept;
    virtual control& text(std::wstring value);

    virtual bool visible() const noexcept;
    virtual control& visible(bool value) noexcept;

    virtual int width() const noexcept;
    virtual control& width(int value);

    virtual int left() const noexcept;
    virtual control& left(int value);

    virtual int top() const noexcept;
    virtual control& top(int value);
    /// @}

    /// @name Events
    /// @{

    event_handler click;
    event_handler back_color_changed;
    event_handler fore_color_changed;
    event_handler location_changed;
    event_handler size_changed;
    event_handler resize;
    /// @}

    /// @name Methods
    /// @{
    
    static std::optional<control_ref> from_handle(HWND handle) noexcept;

    void hide();
    void show();
    /// @}

  protected:

   /// @name Protected Properties
   /// @{
    virtual struct create_params create_params() const noexcept;

    virtual COLORREF default_back_color() const;

    virtual COLORREF default_fore_color() const;

    virtual SIZE default_size() const noexcept;
    /// @}

   /// @name Protected Methods
   /// @{

    void create_handle();

    virtual void def_wnd_proc(message& message);

    void destroy_handle();

    void recreate_handle();

    void reflect_message(HWND handle, message& message);

    void set_bound_core(int x, int y, int width, int height, bounds_specified specified);

    virtual void wnd_proc(message& message);

    virtual void on_click(const event_args& e);

    virtual void on_back_color_changed(const event_args& e);

    virtual void on_fore_color_changed(const event_args& e);

    virtual void on_handle_created(const event_args& e);

    virtual void on_handle_destroyed(const event_args& e);

    virtual void on_location_changed(const event_args& e);

    virtual void on_resize(const event_args& e);

    virtual void on_size_changed(const event_args& e);
    /// @}

  private:
    static LRESULT CALLBACK wnd_proc_(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
    virtual void wm_child_activate(message& message);
    virtual void wm_command(message& message);
    virtual void wm_ctlcolor(message& message);
    virtual void wm_create(message& message);
    virtual void wm_enter_idle(message& message);
    virtual void wm_erasebkgnd(message& message);
    virtual void wm_help(message& message);
    virtual void wm_key_char(message& message);
    virtual void wm_kill_focus(message& message);
    virtual void wm_menu_command(message& message);
    virtual void wm_mouse_down(message& message);
    virtual void wm_mouse_double_click(message& message);
    virtual void wm_mouse_enter(message& message);
    virtual void wm_mouse_leave(message& message);
    virtual void wm_mouse_move(message& message);
    virtual void wm_mouse_up(message& message);
    virtual void wm_mouse_wheel(message& message);
    virtual void wm_move(message& message);
    virtual void wm_notify(message& message);
    virtual void wm_paint(message& message);
    virtual void wm_scroll(message& message);
    virtual void wm_set_focus(message& message);
    virtual void wm_set_text(message& message);
    virtual void wm_show(message& message);
    virtual void wm_size(message& message);
    virtual void wm_sizing(message& message);
 
    inline static std::map<HWND, control*> controls_;
    struct data {
      HBRUSH back_brush = nullptr;
      std::optional<COLORREF> back_color;
      WNDPROC def_wnd_proc = nullptr;
      std::optional<COLORREF> fore_color;
      mutable HWND handle = nullptr;
      HWND parent = nullptr;
      std::wstring text;
      POINT location = { CW_USEDEFAULT, CW_USEDEFAULT };
      SIZE size = { CW_USEDEFAULT, CW_USEDEFAULT };
    };
    std::shared_ptr<data> data_ = std::make_shared<data>();
  };
}