#pragma once

#include "network/iclient.hpp"
#include <enet/enet.h>

namespace bulldog
{
namespace network
{
namespace impl
{
class Client final
  : public ::bulldog::network::iClient
{
public:
  bool connect(std::string const&, uint32_t const) override;
  bool disconnect() override;
  bool connected() const override;

  void send(::bulldog::network::DeliveryType, ...) const override;
  std::vector<...> receive(std::chrono::milliseconds const&) override;
private:

};
}
}
}
