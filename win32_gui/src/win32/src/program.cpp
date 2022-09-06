#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include "../include/debug.h"
#include "../include/forms.h"

using namespace win32;

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
  form1.back_color(RGB(255, 0, 0));
  form1.fore_color(RGB(0, 255, 0));
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

  button1.click = [&](control& sender, const event_args& e) {
    label1.text(L"Dialog result = ");
    my_dialog dialog;
    dialog_result dialog_result = dialog.show_dialog(form1);
    label1.text(string_format(L"Dialog result = %d", static_cast<int>(dialog_result)));
  };

  application::idle = [&](const event_args& e) {
    static auto cpt = 0;
    debug::write_line(string_format(L"idle %d", ++cpt));
  };

  application::application_exit = [&](const event_args& e) {
    static auto cpt = 0;
    debug::write_line(L"Application exit");
  };

  application::thread_exit = [&](const event_args& e) {
    static auto cpt = 0;
    debug::write_line(L"Thread exit");
  };

  application::run(form1);
}
