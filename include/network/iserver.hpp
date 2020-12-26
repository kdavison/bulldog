#pragma once
#include <utility/copyable.hpp>
#include <cstdint>

namespace bulldog
{
namespace network
{
class iServer
  : public ::bulldog::utility::copyable<false>
{
public:
  iServer() = default;
  virtual ~iServer() =  default;

  virtual void start(uint32_t const) = 0;
  virtual bool stop() = 0;
  virtual bool running() const = 0;

  virtual uint32_t clientCount() const = 0;

  virtual void sent(uint32_t, ..., ...) const = 0;
  virtual void broadcast(..., ...) const = 0;

  virtual std::vector<...> poll() = 0;
  virtual void on(uint32_t, ...) = 0;
};
}
}
