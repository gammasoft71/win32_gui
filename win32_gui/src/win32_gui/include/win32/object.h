#pragma once

namespace win32 {
  class object {
  public:
    /// @name Constructors

    /// @{
    object() = default;
    /// @}

    /// @cond
    object(const object&) = default;
    object(object&&) = default;
    virtual ~object() = default;
    /// @endcond

  protected:
    /// @name Protected Properties

    /// @{
    /// @}

  private:
  };
}