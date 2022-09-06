# win32_gui

* C++ Win32 gui draft project used to experiment with [xtd](https://gammasoft71.wixsite.com/xtdpro).
* DO NOT USE this project for your developments.
* I put it at the disposal of the community because it can be an inspiration for you and because it could be a good start to start a [Win32](https://docs.microsoft.com/en-us/windows/win32/controls/window-controls) project properly.

## This project contains

* A basic [application](https://github.com/gammasoft71/win32_gui/blob/main/win32_gui/src/win32/include/application.h) class that allows to start and stop the Windows event loop
* A [control](https://github.com/gammasoft71/win32_gui/blob/main/win32_gui/src/win32/include/control.h) class which is the basis for all other controls like, [form](https://github.com/gammasoft71/win32_gui/blob/main/win32_gui/src/win32/include/form.h), [button](https://github.com/gammasoft71/win32_gui/blob/main/win32_gui/src/win32/include/button.h), [label](https://github.com/gammasoft71/win32_gui/blob/main/win32_gui/src/win32/include/label.h), ...
* An elegant way to receive the events in all the controls and to process them cleanly in C++.

## Remarks

If you want a complete project on which to base your development, please use [xtd](https://gammasoft71.wixsite.com/xtdpro).

## Example

```c++
#include "../include/debug.h"

using namespace win32;

int wmain(int argc, wchar_t* argv[]) {
  form form1;
  form1.back_color(RGB(255, 0, 0));
  form1.fore_color(RGB(0, 255, 0));
  form1.size({800, 450});
  form1.text(L"Form1");

  button button1;
  button1.parent(form1);
  button1.text(L"Click me!");
  button1.location({10, 10});

  label label1;
  label1.parent(form1);
  label1.text(L"Dialog result = ");
  label1.location({ 10, 40 });
  label1.width(200);

  button1.click += [](control& sender, const event_args& e) {
    MessageBox(form1.handle(), L"Hello, World!", L"", MB_OK);
 };

  application::run(form1);
}
```
