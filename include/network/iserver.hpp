#pragma once
#include "utility/copyable.hpp"
#include "network/delivery_type.hpp"
#include <chrono>
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

  virtual void send(uint32_t, ::bulldog::netowrk::DeliveryType, ...) const = 0;
  virtual void broadcast(::bulldog::network::DeliveryType, ...) const = 0;

  virtual std::vector<...> receive(std::chrono::milliseconds const&) = 0;
};
}
}
