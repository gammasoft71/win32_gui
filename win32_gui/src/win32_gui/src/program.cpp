#include "../include/win32_gui"

using namespace win32;
using namespace win32::diagnostics;
using namespace win32::drawing;
using namespace win32::forms;

class my_dialog : public form {
public:
  my_dialog() {
    text(L"Message");
    size({200, 110});

    message.location({ 10, 10 });
    message.parent(*this);
    message.width(180);
    message.text(L"This is a user message");

    ok_button.dialog_result(dialog_result::ok);
    ok_button.location({ 10, 35 });
    ok_button.parent(*this);
    ok_button.text(L"&OK");

    cancel_button.dialog_result(dialog_result::cancel);
    cancel_button.location({ 100, 35 });
    cancel_button.parent(*this);
    cancel_button.text(L"&Cancel");
  }

private:
  label message;
  button ok_button;
  button cancel_button;
};

int wmain(int argc, wchar_t* argv[]) {
  form form1;
  form1.back_color(color::navy);
  form1.fore_color(color::yellow);
  form1.size({ 800, 450 });
  form1.text(L"Form1");

  button button1;
  button1.parent(form1);
  button1.text(L"Click me!");
  button1.location({ 10, 10 });

  label label1;
  label1.parent(form1);
  label1.text(L"Dialog result = ");
  label1.location({ 10, 40 });
  label1.width(200);

  timer timer1;
  timer1.tick += [] {
    static auto cpt = 0;
    debug::write_line(string_format(L"timer %d", ++cpt));
  };

  button1.click += [&](object& sender, const event_args& e) {
    label1.text(L"Dialog result = ");
    /*
    my_dialog dialog;
    dialog.location({300, 200});
    dialog_result dialog_result = dialog.show_dialog(form1);
    label1.text(string_format(L"Dialog result = %d", static_cast<int>(dialog_result)));
    */
    timer1.enabled(!timer1.enabled());
  };

  application::idle += [&](const event_args& e) {
    //static auto cpt = 0;
    //debug::write_line(string_format(L"idle %d", ++cpt));
  };

  application::application_exit += [&](const event_args& e) {
    debug::write_line(L"Application exit");
  };

  application::enter_thread_modal += [&](const event_args& e) {
    debug::write_line(L"Enter thread modal");
  };

  application::leave_thread_modal += [&](const event_args& e) {
    debug::write_line(L"Leave thread modal");
  };

  application::thread_exit += [&](const event_args& e) {
    debug::write_line(L"Thread exit");
  };

  form1.key_down += [&](object& sender, key_event_args& e) {
    debug::write_line(string_format(L"key_down : key_data=0x%04X, modifiers=0x%04X", e.key_data, e.modifiers()));
    e.suppress_key_press = e.key_code() == VK_SPACE;
    e.handled = true;
  };

  form1.key_press += [&](object& sender, key_press_event_args& e) {
    debug::write_line(string_format(L"key_press : key_char='%c'", e.key_char));
  };

  form1.key_up += [&](object& sender, key_event_args& e) {
    debug::write_line(string_format(L"key_up : key_data=0x%04X, modifiers=0x%04X", e.key_data, e.modifiers()));
  };

  form1.mouse_click += [&](object& sender, const mouse_event_args& e) {
    debug::write_line(string_format(L"mouse_click : button=0x%08X, clicks=%d, location={x=%d, y=%d}", e.button, e.clicks, e.x, e.y));
  };

  form1.mouse_double_click += [&](object& sender, const mouse_event_args& e) {
    debug::write_line(string_format(L"mouse_double_click : button=0x%08X, clicks=%d, location={x=%d, y=%d}", e.button, e.clicks, e.x, e.y));
  };

  form1.mouse_down += [&](object& sender, const mouse_event_args& e) {
    debug::write_line(string_format(L"mouse_down : button=0x%08X, clicks=%d, location={x=%d, y=%d}", e.button, e.clicks, e.x, e.y));
  };

  form1.mouse_move += [&](object& sender, const mouse_event_args& e) {
    debug::write_line(string_format(L"mouse_move : location={x=%d, y=%d}", e.x, e.y));
  };

  form1.mouse_up += [&](object& sender, const mouse_event_args& e) {
    debug::write_line(string_format(L"mouse_up : button=0x%08X, clicks=%d, location={x=%d, y=%d}", e.button, e.clicks, e.x, e.y));
  };

  form1.location_changed += [&](object& sender, const event_args& e) {
    debug::write_line(string_format(L"location_changed : location={x=%d, y=%d}", form1.left(), form1.top()));
  };

  form1.move += [&](object& sender, const event_args& e) {
    debug::write_line(string_format(L"move : location={x=%d, y=%d}", form1.left(), form1.top()));
  };

  form1.size_changed += [&](object& sender, const event_args& e) {
    debug::write_line(string_format(L"size_changed : size={width=%d, height=%d}", form1.width(), form1.height()));
  };

  form1.resize += [&](object& sender, const event_args& e) {
    debug::write_line(string_format(L"resize : size={width=%d, height=%d}", form1.width(), form1.height()));
  };

  button1.invalidate();

  application::run(form1);
}
