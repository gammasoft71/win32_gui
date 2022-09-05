#pragma once
#include <string>
#include <typeinfo>
#include <Windows.h>

#define __C_STRING_BUFFER_SIZE__ (4096)

namespace win32 {
  /// @name Methods
  /// @{


  inline LPCWSTR string_format(LPCWSTR format, ...) {
    thread_local static WCHAR buffer[__C_STRING_BUFFER_SIZE__];
    va_list args;
    va_start(args, format);
    wvsprintf(buffer, format, args);
    va_end(args);
    return buffer;
  }

  inline size_t string_format_s(WCHAR* string, size_t size, LPCWSTR format, ...) {
    va_list args;
    va_start(args, format);
    size_t result = 0;
    if (string == nullptr) result = wvsprintf(nullptr, format, args) + 1;
    else result = wvsprintf(string, format, args);
    va_end(args);
    return result;
  }

  inline std::wstring string_replace(const std::wstring& value, const std::wstring& old_string, const std::wstring& new_string) noexcept {
    std::wstring result(value);
    auto old_size = old_string.length();
    auto new_size = new_string.length();
    size_t index = 0;
    while (true) {
      index = result.find(old_string, index);
      if (index == std::wstring::npos) break;
      if (old_size == new_size) result.replace(index, old_size, new_string);
      else {
        result.erase(index, old_string.size());
        result.insert(index, new_string);
      }
      index += new_string.size();
    }
    return result;
  }

  /*
  inline std::wstring demangle(const std::wstring& name) {
  #if defined(_WIN32)
    std::wstring result = name;
    for (auto& item : { L"enum ", L"class ", L"union ", L"struct " })
      result = string_replace(result, item, L"");
    return result;
  #else
    class auto_delete_char_pointer {
    public:
      auto_delete_char_pointer(char* value) : value_(value) {}
      ~auto_delete_char_pointer() { free(value_); }
      char* operator()() const { return value_; }
    private:
      char* value_;
    };
    int32_t status = 0;
    return auto_delete_char_pointer(abi::__cxa_demangle(name.c_str(), 0, 0, &status))();
  #endif
  }

  inline std::wstring get_class_name(const std::wstring& full_name) {
    size_t length = full_name.last_index_of("<");
    if (length == std::wstring::npos) length = full_name.length();
    if (full_name.last_index_of("::", 0, length) == std::wstring::npos) return full_name;
    return full_name.substring(full_name.last_index_of("::", 0, length) + 2);
  }

  template<typename object_t>
  inline std::wstring full_class_name() { return demangle(typeid(object_t).name()); }

  /// @brief Gets the fully qualified class name of the specified object, including the namespace of the specified object.
  /// @return The fully qualified class name of the objec_t, including the namespace of the specified object.
  /// @remarks For example, the fully qualified name of the ustring type is xtd::ustring.
  template<typename object_t>
  inline std::wstring full_class_name(const object_t& object) { return demangle(typeid(object).name()); }

  /// @brief Gets the fully qualified class name of the specified object, including the namespace of the specified object.
  /// @return The fully qualified class name of the objec_t, including the namespace of the specified object.
  /// @remarks For example, the fully qualified name of the ustring type is xtd::ustring.
  inline std::wstring full_class_name(const std::type_info& info) { return demangle(info.name()); }

  /// @brief Gets the class name of the object_t.
  /// @return The class name of the object_t.
  /// @remarks For example, the name of the ustring type is ustring.
  template<typename object_t>
  inline std::wstring class_name() { return get_class_name(full_class_name<object_t>()); }

  /// @brief Gets the class name of the specified object.
  /// @return The class name of the specified object.
  /// @remarks For example, the name of the ustring type is ustring.
  template<typename object_t>
  inline std::wstring class_name(const object_t& object) { return get_class_name(full_class_name(object)); }

  /// @brief Gets the class name of the specified object.
  /// @return The class name of the specified object.
  /// @remarks For example, the name of the ustring type is ustring.
  inline std::wstring class_name(const std::type_info& info) { return get_class_name(full_class_name(info)); }
  */
  /// @}
}