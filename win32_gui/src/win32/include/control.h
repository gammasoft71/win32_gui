#pragma once
#define TRACE /// @todo : Remove define...
#include "debug.h"

#include "bounds_specified.h"
#include "create_params.h"
#include "event_handler.h"
#include "iwin32_window.h"
#include "message.h"
#include "string.h"
#include "window_messages.h"
#include <map>
#include <optional>
#include <Windowsx.h>
#include <Uxtheme.h>

namespace win32 {
  class control;
  using control_ref = std::reference_wrapper<control>;

  class control : public iwin32_window {
  public:
    control() = default;
    virtual ~control();

    // Properties

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

    // Events

    event_handler click;
    event_handler back_color_changed;
    event_handler fore_color_changed;
    event_handler location_changed;
    event_handler size_changed;
    event_handler resize;

    // Methods

    static std::optional<control_ref> from_handle(HWND handle) noexcept;

    void hide();
    void show();

  protected:
    // Properties

    virtual struct create_params create_params() const noexcept;

    virtual COLORREF default_back_color() const;

    virtual COLORREF default_fore_color() const;

    virtual SIZE default_size() const noexcept;

    // Methods

    void create_handle();

    virtual LRESULT def_wnd_proc(const message& message);

    void destroy_handle();

    void recreate_handle();

    LRESULT reflect_message(HWND handle, const message& message);

    void set_bound_core(int x, int y, int width, int height, bounds_specified specified);

    virtual LRESULT wnd_proc(const message& message);

    virtual void on_click(const event_args& e);

    virtual void on_back_color_changed(const event_args& e);

    virtual void on_fore_color_changed(const event_args& e);

    virtual void on_handle_created(const event_args& e);

    virtual void on_handle_destroyed(const event_args& e);

    virtual void on_location_changed(const event_args& e);

    virtual void on_resize(const event_args& e);

    virtual void on_size_changed(const event_args& e);

  private:
    // Methods

    static LRESULT CALLBACK wnd_proc_dispatcher(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
    LRESULT wm_child_activate(const message& message);
    LRESULT wm_command(const message& message);
    LRESULT wm_ctlcolor(const message& message);
    LRESULT wm_create(const message& message);
    LRESULT wm_enter_idle(const message& message);
    LRESULT wm_erasebkgnd(const message& message);
    LRESULT wm_help(const message& message);
    LRESULT wm_key_char(const message& message);
    LRESULT wm_kill_focus(const message& message);
    LRESULT wm_menu_command(const message& message);
    LRESULT wm_mouse_down(const message& message);
    LRESULT wm_mouse_double_click(const message& message);
    LRESULT wm_mouse_enter(const message& message);
    LRESULT wm_mouse_leave(const message& message);
    LRESULT wm_mouse_move(const message& message);
    LRESULT wm_mouse_up(const message& message);
    LRESULT wm_mouse_wheel(const message& message);
    LRESULT wm_move(const message& message);
    LRESULT wm_notify(const message& message);
    LRESULT wm_paint(const message& message);
    LRESULT wm_scroll(const message& message);
    LRESULT wm_set_focus(const message& message);
    LRESULT wm_set_text(const message& message);
    LRESULT wm_show(const message& message);
    LRESULT wm_size(const message& message);
    LRESULT wm_sizing(const message& message);

    // Members

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