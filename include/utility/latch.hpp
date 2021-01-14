#pragma once

#include "utility/copyable.hpp"
#include <atomic>
#include <condition_variable>
#include <mutex>
#include <cstdint>
#include <cassert>

namespace bulldog
{
namespace utility
{
class latch
  : public ::bulldog::utility::copyable<false>
{
private:
  std::atomic<int32_t> _count;
  std::condition_variable _cv;
  std::mutex _mutex;
public:
  explicit latch(const int32_t count)
    : _count(count)
  {
    assert(_count > 0);
  }

  ~latch() = default;

  inline bool try_wait() const noexcept {
    return (_count.load(std::memory_order::memory_order_relaxed) == 0);
  }

  inline void wait() {
    std::unique_lock<typeof(_mutex)> lock(_mutex);
    _cv.wait(lock, [&]{ return (!try_wait());});
  }

  inline void count_down(const int32_t n = 1) {
    assert(n > 0 && _count >= n);
    _count -= n;
    _cv.notify_all();
  }

  inline void arrive_and_wait(const int32_t n = 1) {
    count_down(n);
    wait();
  }
};
}
}
