#pragma once

#include <atomic>
#include <cstdint>
#include <cassert>

namespace bulldog
{
namespace utility
{
class semaphore {
private:

public:
  acquire();
  try_acquire();
  try_acquire_for();
  try_acquire_until();
  release();
};
}
}
