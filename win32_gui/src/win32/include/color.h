#pragma once
#include <Windows.h>

namespace win32 {
  /// @brief Represents an RGBA (red, green, blue, alpha) color.
  struct color {
    /// @brief Gets the red component value of this win32::color class.
    /// @return byte The red component value of this win32::color.
    /// @remarks The color of each pixel is represented as a 32-bit number: 8 bits each for alpha, red, green, and blue (ARGB). The alpha component specifies the transparency of the color: 0 is fully transparent, and 255 is fully opaque. Likewise, an win32::color::a value of 255 represents an opaque color. An win32::color::a value from 1 through 254 represents a semitransparent color. The color becomes more opaque as win32::color::a approaches 255.
    /// @par Examples
    /// The following code example demonstrates the win32::color::a, win32::color::r, win32::color::g, and win32::color::b properties of a win32::color, and the Implicit(size?to?size_f) member.<br>
    /// This example is designed to be used with a Windows Form. Paste the code into the form and call the show_properties_of_slate_blue method from the form's win32::control::paint event-handling method, passing e as win32::paint_event_args.
    /// @code
    /// void show_properties_of_slate_blue(win32::paint_event_args& e) {
    ///   BYTE r = win32::color::slate_blue.r;
    ///   BYTE g = win32::color::slate_blue.g;
    ///   BYTE b = win32::color::slate_blue.b;
    ///   BYTE a = win32::color::slate_blue.a;
    ///   LPWCSTR text = win32::string_format(L"Slate blue has these RGBA values: alpha: %d, red: %d, green: %d, blue: %d}", r, g, b, a);
    ///   e.graphics().draw_string(text, win32::font(font(), win32::font_style::italic), win32::solid_brush(win32::color::slate_blue), RECT {0, 0, width(), height()));
    /// }
    /// @endcode
    BYTE r = 0x00;
    /// @brief Gets the green component value of this win32::color class.
    /// @return byte The green component value of this win32::color.
    /// @remarks The color of each pixel is represented as a 32-bit number: 8 bits each for alpha, red, green, and blue (ARGB). The alpha component specifies the transparency of the color: 0 is fully transparent, and 255 is fully opaque. Likewise, an win32::color::a value of 255 represents an opaque color. An win32::color::a value from 1 through 254 represents a semitransparent color. The color becomes more opaque as win32::color::a approaches 255.
    /// @par Examples
    /// The following code example demonstrates the win32::color::a, win32::color::r, win32::color::g, and win32::color::b properties of a win32::color, and the Implicit(size?to?size_f) member.<br>
    /// This example is designed to be used with a Windows Form. Paste the code into the form and call the show_properties_of_slate_blue method from the form's win32::control::paint event-handling method, passing e as win32::paint_event_args.
    /// @code
    /// void show_properties_of_slate_blue(win32::paint_event_args& e) {
    ///   BYTE r = win32::color::slate_blue.r;
    ///   BYTE g = win32::color::slate_blue.g;
    ///   BYTE b = win32::color::slate_blue.b;
    ///   BYTE a = win32::color::slate_blue.a;
    ///   LPWCSTR text = win32::string_format(L"Slate blue has these RGBA values: alpha: %d, red: %d, green: %d, blue: %d}", r, g, b, a);
    ///   e.graphics().draw_string(text, win32::font(font(), win32::font_style::italic), win32::solid_brush(win32::color::slate_blue), RECT {0, 0, width(), height()));
    /// }
    /// @endcode
    BYTE g = 0x00;
    /// @brief Gets the blue component value of this win32::color class.
    /// @return byte The blue component value of this win32::color.
    /// @remarks The color of each pixel is represented as a 32-bit number: 8 bits each for alpha, red, green, and blue (ARGB). The alpha component specifies the transparency of the color: 0 is fully transparent, and 255 is fully opaque. Likewise, an win32::color::a value of 255 represents an opaque color. An win32::color::a value from 1 through 254 represents a semitransparent color. The color becomes more opaque as win32::color::a approaches 255.
    /// @par Examples
    /// The following code example demonstrates the win32::color::a, win32::color::r, win32::color::g, and win32::color::b properties of a win32::color, and the Implicit(size?to?size_f) member.<br>
    /// This example is designed to be used with a Windows Form. Paste the code into the form and call the show_properties_of_slate_blue method from the form's win32::control::paint event-handling method, passing e as win32::paint_event_args.
    /// @code
    /// void show_properties_of_slate_blue(win32::paint_event_args& e) {
    ///   BYTE r = win32::color::slate_blue.r;
    ///   BYTE g = win32::color::slate_blue.g;
    ///   BYTE b = win32::color::slate_blue.b;
    ///   BYTE a = win32::color::slate_blue.a;
    ///   LPWCSTR text = win32::string_format(L"Slate blue has these RGBA values: alpha: %d, red: %d, green: %d, blue: %d}", r, g, b, a);
    ///   e.graphics().draw_string(text, win32::font(font(), win32::font_style::italic), win32::solid_brush(win32::color::slate_blue), RECT {0, 0, width(), height()));
    /// }
    /// @endcode
    BYTE b = 0x00;
    /// @brief Gets or sets the alpha component value of this win32::color class.
    /// @return The alpha component value of this win32::color.
    /// @remarks The color of each pixel is represented as a 32-bit number: 8 bits each for alpha, red, green, and blue (ARGB). The alpha component specifies the transparency of the color: 0 is fully transparent, and 255 is fully opaque. Likewise, an win32::color::a value of 255 represents an opaque color. An win32::color::a value from 1 through 254 represents a semitransparent color. The color becomes more opaque as win32::color::a approaches 255.
    /// @par Examples
    /// The following code example demonstrates the win32::color::a, win32::color::r, win32::color::g, and win32::color::b properties of a win32::color, and the Implicit(size?to?size_f) member.<br>
    /// This example is designed to be used with a Windows Form. Paste the code into the form and call the show_properties_of_slate_blue method from the form's win32::control::paint event-handling method, passing e as win32::paint_event_args.
    /// @code
    /// void show_properties_of_slate_blue(win32::paint_event_args& e) {
    ///   BYTE r = win32::color::slate_blue.r;
    ///   BYTE g = win32::color::slate_blue.g;
    ///   BYTE b = win32::color::slate_blue.b;
    ///   BYTE a = win32::color::slate_blue.a;
    ///   LPWCSTR text = win32::string_format(L"Slate blue has these RGBA values: alpha: %d, red: %d, green: %d, blue: %d}", r, g, b, a);
    ///   e.graphics().draw_string(text, win32::font(font(), win32::font_style::italic), win32::solid_brush(win32::color::slate_blue), RECT {0, 0, width(), height()));
    /// }
    /// @endcode
    BYTE a = 0xFF;

    operator COLORREF() {
      return RGB(r, g, b);
    }

    static color from_colorref(COLORREF colorref) {
      return color {GetRValue(colorref), GetGValue(colorref), GetBValue(colorref) };
    }

    /// @brief Represents a color that is null.
    static color empty;
    /// @brief Gets a system-defined color that has an ARGB value of 0x00FFFFFF. This field is constant.
    static color transparent;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFF0F8FF. This field is constant.
    static color alice_blue;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFAEBD7. This field is constant.
    static color antique_white;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF00FFFF. This field is constant.
    static color aqua;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF7FFFD4. This field is constant.
    static color aquamarine;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFF0FFFF. This field is constant.
    static color azure;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFF5F5DC. This field is constant.
    static color beige;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFE4C4. This field is constant.
    static color bisque;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF000000. This field is constant.
    static color black;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFEBCD. This field is constant.
    static color blanched_almond;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF0000FF. This field is constant.
    static color blue;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF8A2BE2. This field is constant.
    static color blue_violet;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFA52A2A. This field is constant.
    static color brown;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFDEB887. This field is constant.
    static color burly_wood;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF5F9EA0. This field is constant.
    static color cadet_blue;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF7FFF00. This field is constant.
    static color chartreuse;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFD2691E. This field is constant.
    static color chocolate;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF7F50. This field is constant.
    static color coral;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF6495ED. This field is constant.
    static color cornflower_blue;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFF8DC. This field is constant.
    static color cornsilk;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFDC143C. This field is constant.
    static color crimson;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF00FFFF. This field is constant.
    static color cyan;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF00008B. This field is constant.
    static color dark_blue;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF008B8B. This field is constant.
    static color dark_cyan;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFB8860B. This field is constant.
    static color dark_goldenrod;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFA9A9A9. This field is constant.
    static color dark_gray;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF006400. This field is constant.
    static color dark_green;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFBDB76B. This field is constant.
    static color dark_khaki;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF8B008B. This field is constant.
    static color dark_magenta;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF556B2F. This field is constant.
    static color dark_olive_green;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF8C00. This field is constant.
    static color dark_orange;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF9932CC. This field is constant.
    static color dark_orchid;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF8B0000. This field is constant.
    static color dark_red;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFE9967A. This field is constant.
    static color dark_salmon;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF8FBC8B. This field is constant.
    static color dark_sea_green;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF483D8B. This field is constant.
    static color dark_slate_blue;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF2F4F4F. This field is constant.
    static color dark_slate_gray;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF00CED1. This field is constant.
    static color dark_turquoise;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF9400D3. This field is constant.
    static color dark_violet;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF1493. This field is constant.
    static color deep_pink;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF00BFFF. This field is constant.
    static color deep_sky_blue;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF696969. This field is constant.
    static color dim_gray;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF1E90FF. This field is constant.
    static color dodger_blue;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFB22222. This field is constant.
    static color firebrick;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFAF0. This field is constant.
    static color floral_white;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF228B22. This field is constant.
    static color forest_green;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF00FF. This field is constant.
    static color fuchsia;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFDCDCDC. This field is constant.
    static color gainsboro;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFF8F8FF. This field is constant.
    static color ghost_white;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFD700. This field is constant.
    static color gold;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFDAA520. This field is constant.
    static color goldenrod;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF808080. This field is constant.
    static color gray;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF008000. This field is constant.
    static color green;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFADFF2F. This field is constant.
    static color green_yellow;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFF0FFF0. This field is constant.
    static color honeydew;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF69B4. This field is constant.
    static color hot_pink;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFCD5C5C. This field is constant.
    static color indian_red;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF4B0082. This field is constant.
    static color indigo;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFF0. This field is constant.
    static color ivory;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFF0E68C. This field is constant.
    static color khaki;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFE6E6FA. This field is constant.
    static color lavender;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFF0F5. This field is constant.
    static color lavender_blush;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF7CFC00. This field is constant.
    static color lawn_green;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFACD. This field is constant.
    static color lemon_chiffon;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFADD8E6. This field is constant.
    static color light_blue;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFF08080. This field is constant.
    static color light_coral;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFE0FFFF. This field is constant.
    static color light_cyan;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFAFAD2. This field is constant.
    static color light_goldenrod_yellow;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFD3D3D3. This field is constant.
    static color light_gray;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF90EE90. This field is constant.
    static color light_green;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFB6C1. This field is constant.
    static color light_pink;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFA07A. This field is constant.
    static color light_salmon;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF20B2AA. This field is constant.
    static color light_sea_green;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF87CEFA. This field is constant.
    static color light_sky_blue;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF778899. This field is constant.
    static color light_slate_gray;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFB0C4DE. This field is constant.
    static color light_steel_blue;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFE0. This field is constant.
    static color light_yellow;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF00FF00. This field is constant.
    static color lime;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF32CD32. This field is constant.
    static color lime_green;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFAF0E6. This field is constant.
    static color linen;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF00FF. This field is constant.
    static color magenta;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF800000. This field is constant.
    static color maroon;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF66CDAA. This field is constant.
    static color medium_aquamarine;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF0000CD. This field is constant.
    static color medium_blue;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFBA55D3. This field is constant.
    static color medium_orchid;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF9370DB. This field is constant.
    static color medium_purple;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF3CB371. This field is constant.
    static color medium_sea_green;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF7B68EE. This field is constant.
    static color medium_slate_blue;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF00FA9A. This field is constant.
    static color medium_spring_green;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF48D1CC. This field is constant.
    static color medium_turquoise;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFC71585. This field is constant.
    static color medium_violet_red;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF191970. This field is constant.
    static color midnight_blue;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFF5FFFA. This field is constant.
    static color mint_cream;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFE4E1. This field is constant.
    static color misty_rose;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFE4B5. This field is constant.
    static color moccasin;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFDEAD. This field is constant.
    static color navajo_white;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF000080. This field is constant.
    static color navy;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFDF5E6. This field is constant.
    static color old_lace;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF808000. This field is constant.
    static color olive;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF6B8E23. This field is constant.
    static color olive_drab;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFA500. This field is constant.
    static color orange;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF4500. This field is constant.
    static color orange_red;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFDA70D6. This field is constant.
    static color orchid;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFEEE8AA. This field is constant.
    static color pale_goldenrod;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF98FB98. This field is constant.
    static color pale_green;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFAFEEEE. This field is constant.
    static color pale_turquoise;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFDB7093. This field is constant.
    static color pale_violet_red;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFEFD5. This field is constant.
    static color papaya_whip;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFDAB9. This field is constant.
    static color peach_puff;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFCD853F. This field is constant.
    static color peru;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFC0CB. This field is constant.
    static color pink;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFDDA0DD. This field is constant.
    static color plum;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFB0E0E6. This field is constant.
    static color powder_blue;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF800080. This field is constant.
    static color purple;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF663399. This field is constant.
    static color rebecca_purple;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF0000. This field is constant.
    static color red;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFBC8F8F. This field is constant.
    static color rosy_brown;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF4169E1. This field is constant.
    static color royal_blue;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF8B4513. This field is constant.
    static color saddle_brown;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFA8072. This field is constant.
    static color salmon;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFF4A460. This field is constant.
    static color sandy_brown;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF2E8B57. This field is constant.
    static color sea_green;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFF5EE. This field is constant.
    static color sea_shell;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFA0522D. This field is constant.
    static color sienna;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFC0C0C0. This field is constant.
    static color silver;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF87CEEB. This field is constant.
    static color sky_blue;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF6A5ACD. This field is constant.
    static color slate_blue;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF708090. This field is constant.
    static color slate_gray;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFAFA. This field is constant.
    static color snow;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF00FF7F. This field is constant.
    static color spring_green;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF4682B4. This field is constant.
    static color steel_blue;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFD2B48C. This field is constant.
    static color tan;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF008080. This field is constant.
    static color teal;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFD8BFD8. This field is constant.
    static color thistle;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF6347. This field is constant.
    static color tomato;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF40E0D0. This field is constant.
    static color turquoise;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFEE82EE. This field is constant.
    static color violet;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFF5DEB3. This field is constant.
    static color wheat;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
    static color white;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFF5F5F5. This field is constant.
    static color white_smoke;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFF00. This field is constant.
    static color yellow;
    /// @brief Gets a system-defined color that has an ARGB value of 0xFF9ACD32. This field is constant.
    static color yellow_green;
  };

  /// @cond
  inline color color::transparent{ 0xFF, 0xFF, 0xFF, 0x00 };
  inline color color::alice_blue{ 0xF0, 0xF8, 0xFF, 0xFF };
  inline color color::antique_white{ 0xFA, 0xEB, 0xD7, 0xFF };
  inline color color::aqua{ 0x00, 0xFF, 0xFF, 0xFF };
  inline color color::aquamarine{ 0x7F, 0xFF, 0xD4, 0xFF };
  inline color color::azure{ 0xF0, 0xFF, 0xFF, 0xFF };
  inline color color::beige{ 0xF5, 0xF5, 0xDC, 0xFF };
  inline color color::bisque{ 0xFF, 0xE4, 0xC4, 0xFF };
  inline color color::black{ 0x00, 0x00, 0x00, 0xFF };
  inline color color::blanched_almond{ 0xFF, 0xEB, 0xCD, 0xFF };
  inline color color::blue{ 0x00, 0x00, 0xFF, 0xFF };
  inline color color::blue_violet{ 0x8A, 0x2B, 0xE2, 0xFF };
  inline color color::brown{ 0xA5, 0x2A, 0x2A, 0xFF };
  inline color color::burly_wood{ 0xDE, 0xB8, 0x87, 0xFF };
  inline color color::cadet_blue{ 0x5F, 0x9E, 0xA0, 0xFF };
  inline color color::chartreuse{ 0x7F, 0xFF, 0x00, 0xFF };
  inline color color::chocolate{ 0xD2, 0x69, 0x1E, 0xFF };
  inline color color::coral{ 0xFF, 0x7F, 0x50, 0xFF };
  inline color color::cornflower_blue{ 0x64, 0x95, 0xED, 0xFF };
  inline color color::cornsilk{ 0xFF, 0xF8, 0xDC, 0xFF };
  inline color color::crimson{ 0xDC, 0x14, 0x3C, 0xFF };
  inline color color::cyan{ 0x00, 0xFF, 0xFF, 0xFF };
  inline color color::dark_blue{ 0x00, 0x00, 0x8B, 0xFF };
  inline color color::dark_cyan{ 0x00, 0x8B, 0x8B, 0xFF };
  inline color color::dark_goldenrod{ 0xB8, 0x86, 0x0B, 0xFF };
  inline color color::dark_gray{ 0xA9, 0xA9, 0xA9, 0xFF };
  inline color color::dark_green{ 0x00, 0x64, 0x00, 0xFF };
  inline color color::dark_khaki{ 0xBD, 0xB7, 0x6B, 0xFF };
  inline color color::dark_magenta{ 0x8B, 0x00, 0x8B, 0xFF };
  inline color color::dark_olive_green{ 0x55, 0x6B, 0x2F, 0xFF };
  inline color color::dark_orange{ 0xFF, 0x8C, 0x00, 0xFF };
  inline color color::dark_orchid{ 0x99, 0x32, 0xCC, 0xFF };
  inline color color::dark_red{ 0x8B, 0x00, 0x00, 0xFF };
  inline color color::dark_salmon{ 0xE9, 0x96, 0x7A, 0xFF };
  inline color color::dark_sea_green{ 0x8F, 0xBC, 0x8B, 0xFF };
  inline color color::dark_slate_blue{ 0x48, 0x3D, 0x8B, 0xFF };
  inline color color::dark_slate_gray{ 0x2F, 0x4F, 0x4F, 0xFF };
  inline color color::dark_turquoise{ 0x00, 0xCE, 0xD1, 0xFF };
  inline color color::dark_violet{ 0x94, 0x00, 0xD3, 0xFF };
  inline color color::deep_pink{ 0xFF, 0x14, 0x93, 0xFF };
  inline color color::deep_sky_blue{ 0x00, 0xBF, 0xFF, 0xFF };
  inline color color::dim_gray{ 0x69, 0x69, 0x69, 0xFF };
  inline color color::dodger_blue{ 0x1E, 0x90, 0xFF, 0xFF };
  inline color color::firebrick{ 0xB2, 0x22, 0x22, 0xFF };
  inline color color::floral_white{ 0xFF, 0xFA, 0xF0, 0xFF };
  inline color color::forest_green{ 0x22, 0x8B, 0x22, 0xFF };
  inline color color::fuchsia{ 0xFF, 0x00, 0xFF, 0xFF };
  inline color color::gainsboro{ 0xDC, 0xDC, 0xDC, 0xFF };
  inline color color::ghost_white{ 0xF8, 0xF8, 0xFF, 0xFF };
  inline color color::gold{ 0xFF, 0xD7, 0x00, 0xFF };
  inline color color::goldenrod{ 0xDA, 0xA5, 0x20, 0xFF };
  inline color color::gray{ 0x80, 0x80, 0x80, 0xFF };
  inline color color::green{ 0x00, 0x80, 0x00, 0xFF };
  inline color color::green_yellow{ 0xAD, 0xFF, 0x2F, 0xFF };
  inline color color::honeydew{ 0xF0, 0xFF, 0xF0, 0xFF };
  inline color color::hot_pink{ 0xFF, 0x69, 0xB4, 0xFF };
  inline color color::indian_red{ 0xCD, 0x5C, 0x5C, 0xFF };
  inline color color::indigo{ 0x4B, 0x00, 0x82, 0xFF };
  inline color color::ivory{ 0xFF, 0xFF, 0xF0, 0xFF };
  inline color color::khaki{ 0xF0, 0xE6, 0x8C, 0xFF };
  inline color color::lavender{ 0xE6, 0xE6, 0xFA, 0xFF };
  inline color color::lavender_blush{ 0xFF, 0xF0, 0xF5, 0xFF };
  inline color color::lawn_green{ 0x7C, 0xFC, 0x00, 0xFF };
  inline color color::lemon_chiffon{ 0xFF, 0xFA, 0xCD, 0xFF };
  inline color color::light_blue{ 0xAD, 0xD8, 0xE6, 0xFF };
  inline color color::light_coral{ 0xF0, 0x80, 0x80, 0xFF };
  inline color color::light_cyan{ 0xE0, 0xFF, 0xFF, 0xFF };
  inline color color::light_goldenrod_yellow{ 0xFA, 0xFA, 0xD2, 0xFF };
  inline color color::light_gray{ 0xD3, 0xD3, 0xD3, 0xFF };
  inline color color::light_green{ 0x90, 0xEE, 0x90, 0xFF };
  inline color color::light_pink{ 0xFF, 0xB6, 0xC1, 0xFF };
  inline color color::light_salmon{ 0xFF, 0xA0, 0x7A, 0xFF };
  inline color color::light_sea_green{ 0x20, 0xB2, 0xAA, 0xFF };
  inline color color::light_sky_blue{ 0x87, 0xCE, 0xFA, 0xFF };
  inline color color::light_slate_gray{ 0x77, 0x88, 0x99, 0xFF };
  inline color color::light_steel_blue{ 0xB0, 0xC4, 0xDE, 0xFF };
  inline color color::light_yellow{ 0xFF, 0xFF, 0xE0, 0xFF };
  inline color color::lime{ 0x00, 0xFF, 0x00, 0xFF };
  inline color color::lime_green{ 0x32, 0xCD, 0x32, 0xFF };
  inline color color::linen{ 0xFA, 0xF0, 0xE6, 0xFF };
  inline color color::magenta{ 0xFF, 0x00, 0xFF, 0xFF };
  inline color color::maroon{ 0x80, 0x00, 0x00, 0xFF };
  inline color color::medium_aquamarine{ 0x66, 0xCD, 0xAA, 0xFF };
  inline color color::medium_blue{ 0x00, 0x00, 0xCD, 0xFF };
  inline color color::medium_orchid{ 0xBA, 0x55, 0xD3, 0xFF };
  inline color color::medium_purple{ 0x93, 0x70, 0xDB, 0xFF };
  inline color color::medium_sea_green{ 0x3C, 0xB3, 0x71, 0xFF };
  inline color color::medium_slate_blue{ 0x7B, 0x68, 0xEE, 0xFF };
  inline color color::medium_spring_green{ 0x00, 0xFA, 0x9A, 0xFF };
  inline color color::medium_turquoise{ 0x48, 0xD1, 0xCC, 0xFF };
  inline color color::medium_violet_red{ 0xC7, 0x15, 0x85, 0xFF };
  inline color color::midnight_blue{ 0x19, 0x19, 0x70, 0xFF };
  inline color color::mint_cream{ 0xF5, 0xFF, 0xFA, 0xFF };
  inline color color::misty_rose{ 0xFF, 0xE4, 0xE1, 0xFF };
  inline color color::moccasin{ 0xFF, 0xE4, 0xB5, 0xFF };
  inline color color::navajo_white{ 0xFF, 0xDE, 0xAD, 0xFF };
  inline color color::navy{ 0x00, 0x00, 0x80, 0xFF };
  inline color color::old_lace{ 0xFD, 0xF5, 0xE6, 0xFF };
  inline color color::olive{ 0x80, 0x80, 0x00, 0xFF };
  inline color color::olive_drab{ 0x6B, 0x8E, 0x23, 0xFF };
  inline color color::orange{ 0xFF, 0xA5, 0x00, 0xFF };
  inline color color::orange_red{ 0xFF, 0x45, 0x00, 0xFF };
  inline color color::orchid{ 0xDA, 0x70, 0xD6, 0xFF };
  inline color color::pale_goldenrod{ 0xEE, 0xE8, 0xAA, 0xFF };
  inline color color::pale_green{ 0x98, 0xFB, 0x98, 0xFF };
  inline color color::pale_turquoise{ 0xAF, 0xEE, 0xEE, 0xFF };
  inline color color::pale_violet_red{ 0xDB, 0x70, 0x93, 0xFF };
  inline color color::papaya_whip{ 0xFF, 0xEF, 0xD5, 0xFF };
  inline color color::peach_puff{ 0xFF, 0xDA, 0xB9, 0xFF };
  inline color color::peru{ 0xCD, 0x85, 0x3F, 0xFF };
  inline color color::pink{ 0xFF, 0xC0, 0xCB, 0xFF };
  inline color color::plum{ 0xDD, 0xA0, 0xDD, 0xFF };
  inline color color::powder_blue{ 0xB0, 0xE0, 0xE6, 0xFF };
  inline color color::purple{ 0x80, 0x00, 0x80, 0xFF };
  inline color color::rebecca_purple{ 0x66, 0x33, 0x99, 0xFF };
  inline color color::red{ 0xFF, 0x00, 0x00, 0xFF };
  inline color color::rosy_brown{ 0xBC, 0x8F, 0x8F, 0xFF };
  inline color color::royal_blue{ 0x41, 0x69, 0xE1, 0xFF };
  inline color color::saddle_brown{ 0x8B, 0x45, 0x13, 0xFF };
  inline color color::salmon{ 0xFA, 0x80, 0x72, 0xFF };
  inline color color::sandy_brown{ 0xF4, 0xA4, 0x60, 0xFF };
  inline color color::sea_green{ 0x2E, 0x8B, 0x57, 0xFF };
  inline color color::sea_shell{ 0xFF, 0xF5, 0xEE, 0xFF };
  inline color color::sienna{ 0xA0, 0x52, 0x2D, 0xFF };
  inline color color::silver{ 0xC0, 0xC0, 0xC0, 0xFF };
  inline color color::sky_blue{ 0x87, 0xCE, 0xEB, 0xFF };
  inline color color::slate_blue{ 0x6A, 0x5A, 0xCD, 0xFF };
  inline color color::slate_gray{ 0x70, 0x80, 0x90, 0xFF };
  inline color color::snow{ 0xFF, 0xFA, 0xFA, 0xFF };
  inline color color::spring_green{ 0x00, 0xFF, 0x7F, 0xFF };
  inline color color::steel_blue{ 0x46, 0x82, 0xB4, 0xFF };
  inline color color::tan{ 0xD2, 0xB4, 0x8C, 0xFF };
  inline color color::teal{ 0x00, 0x80, 0x80, 0xFF };
  inline color color::thistle{ 0xD8, 0xBF, 0xD8, 0xFF };
  inline color color::tomato{ 0xFF, 0x63, 0x47, 0xFF };
  inline color color::turquoise{ 0x40, 0xE0, 0xD0, 0xFF };
  inline color color::violet{ 0xEE, 0x82, 0xEE, 0xFF };
  inline color color::wheat{ 0xF5, 0xDE, 0xB3, 0xFF };
  inline color color::white{ 0xFF, 0xFF, 0xFF, 0xFF };
  inline color color::white_smoke{ 0xF5, 0xF5, 0xF5, 0xFF };
  inline color color::yellow{ 0xFF, 0xFF, 0x00, 0xFF };
  inline color color::yellow_green{ 0x9A, 0xCD, 0x32, 0xFF };
  /// @endcond
}