#pragma once
#include "../event.h"
#include "../event_handler.h"
#include "../string.h"
#include "../drawing/color.h"
#include "bounds_specified.h"
#include "control_styles.h"
#include "create_params.h"
#include "help_event_handler.h"
#include "iwin32_window.h"
#include "key_event_handler.h"
#include "key_press_event_handler.h"
#include "message.h"
#include "mouse_event_handler.h"
#include <map>
#include <optional>
#include <Windowsx.h>
#include <Uxtheme.h>

namespace win32 {
  namespace forms {
    /// @cond
    class control;
    using control_ref = std::reference_wrapper<control>;
    /// @endcond

    /// @brief Defines the base class for controls, which are components with visual representation.
    /// @remarks To create your own control class, inherit from the xtd::forms::user_control, xtd::forms::control classes, or from the other Windows Forms provided controls.
    /// @remarks The xtd::forms::control class implements very basic functionality required by classes that display information to the user. It handles user input through the keyboard and pointing devices. It handles message routing and security. It defines the bounds of a control (its position and size), although it does not implement painting. It provides a window handle (hWnd).
    /// @remarks Windows Forms controls use ambient properties so child controls can appear like their surrounding environment. An ambient property is a control property that, if not set, is retrieved from the xtd::forms::control::parent control. If the control does not have a parent, and the property is not set, the control attempts to determine the value of the ambient property through the site property. If the control is not sited, if the site does not support ambient properties, or if the property is not set on the ambient_properties, the control uses its own default values. Typically, an ambient property represents a characteristic of a control, such as xtd::forms::control::back_color, that is communicated to a child control. For example, a button will have the same xtd::forms::control::back_color as its parent form by default. Ambient properties provided by the control class include: xtd::forms::control::cursor, xtd::forms::control::font, xtd::forms::control::back_color, xtd::forms::control::fore_color, and xtd::forms::control::right_to_left.
    /// @remarks The majority of the controls in the xtd::forms namespace use the underlying Windows common control as a base to build on.
    class control : public iwin32_window {
    protected:
      /// @brief Represents the current control state.
      enum class state {
        empty = 0,
        creating = 0b1,
        created = 0b10,
        destroying = 0b100,
        destroyed = 0b1000,
        creating_handle = 0b10000,
        recreate = 0b100000,
        parent_recreating = 0b1000000,

        client_size_setted = 0b10000000,
        modal = 0b100000000,
        top_level = 0b1000000000,
        visible = 0b10000000000,
        enabled = 0b100000000000,
        auto_size = 0b1000000000000,
        tab_stop = 0b10000000000000,
        allow_drop = 0b100000000000000,
        drop_target = 0b1000000000000000,

        layout_deferred = 0b10000000000000000,
        docked = 0b100000000000000000,

        double_click_fired = 0b1000000000000000000,
        double_buffered = 0b10000000000000000000,
      };
    public:
      /// @name Constructors

      /// @{
      /// @brief Initializes a new instance of the xtd::forms::control class with default settings.
      /// @remarks The xtd::forms::control class is the base class for all controls used in a Windows Forms application. Because this class is not typically used to create an instance of the class, this constructor is typically not called directly but is instead called by a derived class.
      control();
      /// @}

      /// @cond
      control(const control&) = delete;
      control(control&&) = delete;
      ~control();
      /// @endcond

      /// @name Properties

      /// @{
      virtual COLORREF back_color() const noexcept;
      virtual control& back_color(COLORREF value);
      virtual control& back_color(nullptr_t value);

      virtual int bottom() const noexcept;

      virtual RECT client_rectangle() const noexcept;

      virtual SIZE client_size() const noexcept;
      virtual control& client_size(SIZE value);

      virtual bool enabled() const noexcept;
      virtual control& enabled(bool value);

      bool focused() const noexcept;

      virtual COLORREF fore_color() const noexcept;
      virtual control& fore_color(COLORREF value);
      virtual control& fore_color(nullptr_t value);

      virtual HWND handle() const noexcept;

      virtual int height() const noexcept;
      virtual control& height(int value);

      virtual int left() const noexcept;
      virtual control& left(int value);

      virtual POINT location() const noexcept;
      virtual control& location(POINT value);

      static UINT modifier_keys();

      virtual std::optional<control_ref> parent() const noexcept;
      virtual control& parent(const control& value);
      virtual control& parent(nullptr_t value);

      virtual int right() const noexcept;

      virtual SIZE size() const noexcept;
      virtual control& size(SIZE value);

      virtual const std::wstring& text() const noexcept;
      virtual control& text(std::wstring value);

      virtual int top() const noexcept;
      virtual control& top(int value);

      virtual bool visible() const noexcept;
      virtual control& visible(bool value) noexcept;

      virtual int width() const noexcept;
      virtual control& width(int value);
      /// @}

      /// @name Events

      /// @{
      /// @brief Occurs when the value of the win32::forms::control::back_color property changes.
      /// @remarks This event is raised if the xtd::forms::control::back_color property is changed by either a programmatic modification or user interaction.
      event<control, event_handler> back_color_changed;

      event<control, event_handler> click;

      event<control, event_handler> client_size_changed;

      event<control, event_handler> double_click;

      event<control, event_handler> enabled_changed;

      event<control, event_handler> fore_color_changed;

      event<control, event_handler> get_focus;

      event<control, help_event_handler> help_requested;

      event<control, key_event_handler> key_down;

      event<control, key_press_event_handler> key_press;

      event<control, key_event_handler> key_up;

      event<control, event_handler> location_changed;

      event<control, event_handler> lost_focus;

      event<control, mouse_event_handler> mouse_click;

      event<control, mouse_event_handler> mouse_double_click;

      event<control, mouse_event_handler> mouse_down;

      event<control, event_handler> mouse_enter;

      event<control, mouse_event_handler> mouse_horizontal_wheel;

      event<control, event_handler> mouse_leave;

      event<control, mouse_event_handler> mouse_move;

      event<control, mouse_event_handler> mouse_up;

      event<control, mouse_event_handler> mouse_wheel;

      event<control, event_handler> move;

      event<control, event_handler> parent_changed;

      event<control, event_handler> resize;

      event<control, event_handler> size_changed;

      event<control, event_handler> text_changed;

      event<control, event_handler> visible_changed;
      /// @}

      /// @name Methods

      /// @{
      void create_control();

      void destroy_control();

      static std::optional<control_ref> from_child_handle(HWND handle) noexcept;
      static std::optional<control_ref> from_handle(HWND handle) noexcept;

      void hide();

      /// @brief Invalidates the entire surface of the control and causes the control to be redrawn.
      /// @remarks Calling the invalidate method does not force a synchronous paint; to force a synchronous paint, call the update method after calling the Invalidate method. When this method is called with no parameters, the entire client area is added to the update region.
      virtual void invalidate() const;

      /// @brief Invalidates a specific region of the control and causes a paint message to be sent to the control. Optionally, invalidates the child controls assigned to the control.
      /// @param invalidate_children true to invalidate the control's child controls; otherwise, false.
      /// @remarks Calling the invalidate method does not force a synchronous paint; to force a synchronous paint, call the update method after calling the Invalidate method. When this method is called with no parameters, the entire client area is added to the update region.
      virtual void invalidate(bool invalidate_children) const;

      /// @brief Invalidates the specified region of the control (adds it to the control's update region, which is the area that will be repainted at the next paint operation), and causes a paint message to be sent to the control.
      /// @param rect A RECT that represents the region to invalidate.
      /// @remarks Calling the invalidate method does not force a synchronous paint; to force a synchronous paint, call the update method after calling the Invalidate method. When this method is called with no parameters, the entire client area is added to the update region.
      virtual void invalidate(RECT rect) const;

      /// @brief Invalidates the specified region of the control (adds it to the control's update region, which is the area that will be repainted at the next paint operation), and causes a paint message to be sent to the control. Optionally, invalidates the child controls assigned to the control.
      /// @param rect A RECT that represents the region to invalidate.
      /// @param invalidate_children true to invalidate the control's child controls; otherwise, false.
      /// @remarks Calling the invalidate method does not force a synchronous paint; to force a synchronous paint, call the update method after calling the Invalidate method. When this method is called with no parameters, the entire client area is added to the update region.
      virtual void invalidate(RECT rect, bool invalidate_children) const;

      /// @brief Invalidates the specified region of the control (adds it to the control's update region, which is the area that will be repainted at the next paint operation), and causes a paint message to be sent to the control.
      /// @param region An HRGN that represents the region to invalidate.
      /// @remarks Calling the invalidate method does not force a synchronous paint; to force a synchronous paint, call the update method after calling the Invalidate method. When this method is called with no parameters, the entire client area is added to the update region.
      virtual void invalidate(HRGN region) const;

      /// @brief Invalidates the specified region of the control (adds it to the control's update region, which is the area that will be repainted at the next paint operation), and causes a paint message to be sent to the control. Optionally, invalidates the child controls assigned to the control.
      /// @param region An HRGN that represents the region to invalidate.
      /// @param invalidate_children true to invalidate the control's child controls; otherwise, false.
      /// @remarks Calling the invalidate method does not force a synchronous paint; to force a synchronous paint, call the update method after calling the Invalidate method. When this method is called with no parameters, the entire client area is added to the update region.
      virtual void invalidate(HRGN region, bool invalidate_children) const;

      bool is_handle_created() const noexcept;

      /// @brief Computes the location of the specified screen point into client coordinates.
      /// @param p The screen coordinate xtd::drawing::point to convert.
      /// @return A xtd::drawing::point that represents the converted xtd::drawing::point, p, in client coordinates.
      POINT point_to_client(const POINT& p) const;

      /// @brief Computes the location of the specified client point into screen coordinates.
      /// @param p The client coordinate  xtd::drawing::point to convert.
      /// @return A xtd::drawing::point that represents the converted  xtd::drawing::point, p, in screen coordinates.
      POINT point_to_screen(const POINT& p) const;

      virtual void refresh() const;

      void show();

      virtual void update() const;
      /// @}

    protected:

      /// @name Protected Properties

      /// @{
      virtual win32::forms::create_params create_params() const noexcept;

      virtual COLORREF default_back_color() const;

      virtual COLORREF default_fore_color() const;

      virtual SIZE default_size() const noexcept;

      DWORD window_ex_style() const;
      DWORD window_style() const;

      /// @}

     /// @name Protected Methods

     /// @{
      void create_handle();

      virtual void def_wnd_proc(message& message);

      void destroy_handle();

      /// @brief Retrieves the value of the specified control style bit for the control.
      /// @param flag The control_styles bit to return the value from.
      /// @return true if the specified control style bit is set to true; otherwise, false.
      /// @remarks Control style bit flags are used to categorize supported behavior. A control can enable a style by calling the set_style method and passing in the appropriate control_styles bit and the bool value to set the bit to. To determine the value assigned to a specified control_styles bit, use the get_style method and pass in the control_styles member to evaluate.
      bool get_style(control_styles flag) const;

      virtual void on_back_color_changed(const event_args& e);

      virtual void on_click(const event_args& e);

      virtual void on_client_size_changed(const event_args& e);

      virtual void on_create_control();

      virtual void on_destroy_control();

      virtual void on_double_click(const event_args& e);

      virtual void on_enabled_changed(const event_args& e);

      virtual void on_fore_color_changed(const event_args& e);

      virtual void on_get_focus(const event_args& e);

      virtual void on_handle_created(const event_args& e);

      virtual void on_handle_destroyed(const event_args& e);

      virtual void on_help_requested(help_event_args& e);

      virtual void on_key_down(key_event_args& e);

      virtual void on_key_press(key_press_event_args& e);

      virtual void on_key_up(key_event_args& e);

      virtual void on_location_changed(const event_args& e);

      virtual void on_lost_focus(const event_args& e);

      virtual void on_mouse_click(const mouse_event_args& e);

      virtual void on_mouse_double_click(const mouse_event_args& e);

      virtual void on_mouse_down(const mouse_event_args& e);

      virtual void on_mouse_enter(const event_args& e);

      virtual void on_mouse_horizontal_wheel(const mouse_event_args& e);

      virtual void on_mouse_leave(const event_args& e);

      virtual void on_mouse_move(const mouse_event_args& e);

      virtual void on_mouse_up(const mouse_event_args& e);

      virtual void on_mouse_wheel(const mouse_event_args& e);

      virtual void on_move(const event_args& e);

      virtual void on_parent_changed(const event_args& e);

      virtual void on_resize(const event_args& e);

      virtual void on_size_changed(const event_args& e);

      virtual void on_text_changed(const event_args& e);

      virtual void on_visible_changed(const event_args& e);

      void recreate_handle();

      void reflect_message(HWND handle, message& message);

      void set_bound_core(int x, int y, int width, int height, bounds_specified specified);

      /// @brief Sets a specified control_styles flag to either true or false.
      /// @param flag The control_styles bit to set.
      /// @param value true to apply the specified style to the control; otherwise, false.
      /// @remarks Control style bit flags are used to categorize supported behavior. A control can enable a style by calling the set_style method and passing in the appropriate control_styles bit (or bits) and the bool value to set the bit(s) to. To determine the value assigned to a specified control_styles bit, use the get_style method and pass in the control_styles member to evaluate.
      /// @warning Setting the control style bits can substantially change the behavior of the control. Review the control_styles enumeration documentation to understand the effects of changing the control style bits before calling the set_style method.
      void set_style(control_styles flag, bool value);

      virtual void wnd_proc(message& message);
      /// @}

      /// @cond
      bool get_state(control::state flag) const;
      void set_state(control::state flag, bool value);
      /// @endcond

    private:
      static LRESULT CALLBACK wnd_proc_(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
      void wm_child_activate(message& message);
      void wm_command(message& message);
      void wm_command_control(message& message);
      void wm_ctlcolor(message& message);
      void wm_ctlcolor_control(message& message);
      void wm_create(message& message);
      void wm_destroy(message& message);
      void wm_drop_files(message& message);
      void wm_enter_idle(message& message);
      void wm_erasebkgnd(message& message);
      void wm_help(message& message);
      void wm_key_char(message& message);
      void wm_kill_focus(message& message);
      void wm_menu_command(message& message);
      void wm_mouse_down(message& message);
      void wm_mouse_double_click(message& message);
      void wm_mouse_enter(message& message);
      void wm_mouse_leave(message& message);
      void wm_mouse_move(message& message);
      void wm_mouse_up(message& message);
      void wm_mouse_wheel(message& message);
      void wm_move(message& message);
      void wm_notify(message& message);
      void wm_notify_control(message& message);
      void wm_paint(message& message);
      void wm_scroll(message& message);
      void wm_scroll_control(message& message);
      void wm_set_focus(message& message);
      void wm_set_text(message& message);
      void wm_show(message& message);
      void wm_size(message& message);
      void wm_sizing(message& message);

      inline static std::map<HWND, control*> handles_;
      inline static UINT modifier_keys_ = 0;
      inline static mouse_buttons mouse_buttons_;
      inline static std::vector<control_ref> top_level_controls_;
      struct data {
        HBRUSH back_brush = nullptr;
        std::optional<COLORREF> back_color;
        std::vector<control_ref> controls;
        WNDPROC def_wnd_proc = nullptr;
        bool focused = false;
        std::optional<COLORREF> fore_color;
        mutable HWND handle = nullptr;
        HWND parent = nullptr;
        std::wstring text;
        POINT location = { CW_USEDEFAULT, CW_USEDEFAULT };
        bool mouse_in = false;
        SIZE size = { CW_USEDEFAULT, CW_USEDEFAULT };
        control::state state = control::state::empty;
        control_styles style = control_styles::none;
        DWORD window_ex_style = 0;
        DWORD window_style = WS_OVERLAPPED;
        bool suppress_key_press = false;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}