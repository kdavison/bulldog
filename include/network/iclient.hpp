#pragma once
#include "utility/copyable.hpp"
#include "network/delivery_type.hpp"
#include <string>
#include <chrono>
#include <cstdint>

namespace bulldog
{
namespace network
{
class iClient
  : public ::bulldog::utility::copyable<false>
{
public:
  iClient() = default;
  virtual ~iClient() = default;

  virtual bool connect(std::string const&, uint32_t const) = 0;
  virtual bool disconnect() = 0;
  virtual bool connected() const = 0;

  virtual void send(::bulldog::network::DeliveryType, ...) const = 0;
  virtual std::vector<...> receive(std::chrono::milliseconds const&) = 0;

  virtual void on(uint32_t const, ...) = 0;
};
}
}
