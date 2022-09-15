#include "../../../include/win32/forms/timer.h"

using namespace win32;
using namespace win32::forms;

timer::~timer() {
  stop();
}

bool timer::enabled() const noexcept {
  return data_->enabled;
}

timer& timer::enabled(bool value) {
  if (data_->enabled == value) return *this;
  data_->enabled = value;
  if (data_->enabled) create_timer();
  else destroy_timer();
  return *this;
}

UINT timer::interval() const noexcept {
  return data_->interval;
}

timer& timer::interval(UINT value) {
  if (data_->interval == value) return *this;
  data_->interval = value;
  if (data_->enabled != 0) {
    destroy_timer();
    create_timer();
  }
  return *this;
}

void timer::on_tick(const event_args& e) {
  tick(*this, e);
}

void timer::create_timer() {
  if (data_->id_event != 0) return;
  data_->id_event = SetTimer(nullptr, 0, data_->interval, &timer_proc_);
  if (data_->id_event != 0) id_events_[data_->id_event] = this;
}

void timer::destroy_timer() {
  if (data_->id_event == 0) return;
  id_events_.erase(data_->id_event);
  KillTimer(nullptr, data_->id_event);
  data_->id_event = 0;
}

timer* timer::from_id_event(UINT_PTR handle) noexcept {
  try {
    auto it = id_events_.find(handle);
    if (it != id_events_.end())
      return it->second;
    return nullptr;
  } catch (...) {
    return nullptr;
  }
}

void timer::timer_proc(HWND hwnd, UINT msg, UINT_PTR id_event, DWORD time) {
  on_tick(event_args::empty);
}

void timer::timer_proc_(HWND hwnd, UINT msg, UINT_PTR id_event, DWORD time) {
  auto timer = from_id_event(id_event);
  if (msg == WM_TIMER && timer != nullptr)
    timer->timer_proc(hwnd, msg, id_event, time);
}
