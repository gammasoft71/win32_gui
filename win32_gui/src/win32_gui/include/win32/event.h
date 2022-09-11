#pragma once

namespace win32 {
  template<typename object_t, typename handler_t>
  class event : protected handler_t {
    friend object_t;
  public:
    /// @name Methods

    /// @{
    bool is_empty() const noexcept { return handler_t::is_empty(); }
    /// @}

    /// @name Operators

    /// @{
    handler_t& operator+=(const handler_t& handler) noexcept {
      return handler_t::operator+=(handler);
    }

    handler_t& operator+=(const typename handler_t::function_t& function) noexcept {
      return handler_t::operator+=(function);
    }

    template<typename fn_t>
    handler_t& operator+=(fn_t function) noexcept {
      return handler_t::operator+=(function);
    }

    handler_t& operator-=(const handler_t& handler) noexcept {
      return handler_t::operator-=(handler);
    }

    handler_t& operator-=(const typename handler_t::function_t& function) noexcept {
      return handler_t::operator-=(function);
    }

    template<typename fn_t>
    handler_t& operator-=(fn_t function) noexcept {
      return handler_t::operator-=(function);
    }

    /// @brief Clear event.
    void clear() noexcept {
      handler_t::clear();
    }
  };
}
