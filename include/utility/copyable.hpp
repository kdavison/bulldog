#pragma once

namespace bulldog
{
namespace utility
{
template<bool>
struct copyable {
protected:
  ~copyable() = default;
};

template<>
struct copyable<false> {
  copyable(copyable const&) = delete;
  copyable& operator=(copyable const&) = delete;
protected:
  ~copyable() = default;
};
}
}
