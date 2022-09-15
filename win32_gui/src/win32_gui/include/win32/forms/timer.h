#pragma once
#include "component.h"
#include "../event_handler.h"
#include "../event.h"
#include <Windows.h>
#include <map>
#include <memory>

namespace win32 {
  namespace forms {
    class timer final : public component {
    public:
      /// @name Constructors

      /// @{
      timer() = default;
      ~timer();
      /// @}

     /// @name Properties

      /// @{
      bool enabled() const noexcept;
      timer& enabled(bool value);

      UINT interval() const noexcept;
      timer& interval(UINT value);
      /// @}

     /// @name Events

      /// @{
      event<timer, event_handler> tick;
      /// @}

     /// @name Methods

      /// @{
      void start() { enabled(true); }
      
      void stop() { enabled(false); }
      /// @}

    protected:
      /// @name Protected Properties

      /// @{
      void on_tick(const event_args& e);
        /// @}

    private:
      void create_timer();
      void destroy_timer();
      static timer* timer::from_id_event(UINT_PTR id_event) noexcept;
      void timer_proc(HWND hwnd, UINT msg, UINT_PTR id_event, DWORD time);
      static void timer_proc_(HWND hwnd, UINT msg, UINT_PTR id_event, DWORD time);
      inline static std::map<UINT_PTR, timer*> id_events_;
      struct data {
        bool enabled = false;
        UINT_PTR id_event = 0;
        UINT interval = 100;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}