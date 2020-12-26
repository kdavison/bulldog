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

  void send(..., ...) const override;
  ... request(uint32_t const, ...) override;
  std::vector<...> poll() override;

  on(uint32_t const, ...) override;
private:

};
}
}
}
